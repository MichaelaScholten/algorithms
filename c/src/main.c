#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#include "data.h"
#include "sort.h"
#include "search.h"

/// @brief Calculates the number of seconds since a certain point in clock time
/// @param since the time to calculate the seconds from
/// @return the number of seconds since the specified point in clock time
double seconds_since(const clock_t since){
    return (double)(clock() - since) / CLOCKS_PER_SEC;
}

/// @brief Generates random data
/// @param length the length of the data
/// @return the generated data
Vec generate_unsorted(const size_t length){
    // Initialize the random number generator
    srand(clock() + time(NULL));

    // Create the Vec
    Vec result = Vec_new(length);

    // Add random numbers to the Vec and return the result
    for(size_t i = 0;i < length;i++){
        Vec_push(&result, rand());
    }
    return result;
}

/// @brief Checks whether data is sorted
/// @param data the data to check
/// @return whether the data is sorted
bool is_sorted(const Vec *data){
    // Return true if the Vec doesn't exist or is empty
    if(data == NULL || data->value == NULL){
        return true;
    }

    // Iterate through the Vec, return false if any items are in the wrong order
    for(size_t i = 1;i < data->length;i++){
        if(data->value[i - 1] > data->value[i]){
            return false;
        }
    }
    return true;
}

/// @brief Tests whether a sorting function works as expected
/// @param name the name of the function
/// @param algorithm the function pointer
/// @param length the length of data to test the function against
void attempt_sort(const char *name, void(*algorithm)(Vec*), const size_t length){
    // Start measuring performance
    const clock_t start = clock();

    // Generate the data
    Vec data = generate_unsorted(length);

    // Sort the data
    algorithm(&data);

    // Display an error message on failure
    if(!is_sorted(&data)){
        // Start displaying the error message
        printf("%s failed:", name);

        // Data is empty (bug in is_sorted function)
        if(data.length == 0 || data.value == NULL){
            perror(" empty");
            return;
        }

        // Display the first 10 values
        printf(" %lu", data.value[0]);
        for(size_t i = 1;i < data.length && i < 10;i++){
            printf(", %lu", data.value[i]);
        }
        putchar('\n');

        // Deallocate the data and exit the application
        Vec_drop(&data);
        exit(EXIT_FAILURE);
    }

    // Display performance and drop the data.
    printf("%s: passed in %lf seconds\n", name, seconds_since(start));
    Vec_drop(&data);
}

/// @brief Generate sorted data
/// @param length the number of values to generate
/// @return the generated data
Vec generated_sorted(const size_t length){
    // Create the Vec
    Vec result = Vec_new(length);

    // Fill it with data
    for(size_t i = 0;i < length;i++){
        Vec_push(&result, i);
    }
    return result;
}

/// @brief Tests whether a search algorithm can find every value in a sorted array
/// @param name the name of the function
/// @param algorithm the function pointer
/// @param length the length of the data to test the function on
void attempt_search(const char *name, SearchResult(*algorithm)(const Vec*,const size_t), const size_t length){
    // Start measuring performance
    const clock_t start = clock();

    // Generate the data
    Vec data = generated_sorted(length);

    // Test the function for every value
    for(size_t i = 0;i < length;i++){
        // Try to search the current value
        SearchResult result = algorithm(&data, i);
        
        // If the value wasn't found or it was found at the wrong index, exit with an error message
        if(!result.found){
            printf("Failed to find %lu with %s\n", i, name);
            exit(EXIT_FAILURE);
        }else if(result.index != i){
            printf("Found %lu at the wrong index (%lu)\n", i, result.index);
            exit(EXIT_FAILURE);
        }
    }

    // Try to find that's not in the array, exit with an error message if found
    if(algorithm(&data, length).found){
        printf("Found non-existent value with %s\n", name);
        exit(EXIT_FAILURE);
    }

    // Display the performance and drop the data
    printf("%s: passed in %lf seconds\n", name, seconds_since(start));
    Vec_drop(&data);
}

int main(){
    // Test the sorting functions
    attempt_sort("bubble sort", bubble_sort, 30000);
    attempt_sort("insertion sort", insertion_sort, 50000);
    attempt_sort("merge sort", merge_sort, 100000000);
    attempt_sort("selection sort", selection_sort, 30000);

    // Test the search functions
    attempt_search("linear search", linear_search, 50000);
    attempt_search("binary search", binary_search, 20000000);
}
