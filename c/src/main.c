#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#include "data.h"
#include "sort.h"
#include "search.h"

double seconds_since(const clock_t since){
    return (double)(clock() - since) / CLOCKS_PER_SEC;
}

Vec generate_unsorted(const size_t length){
    srand(clock() + time(NULL));
    Vec result = Vec_new(length);
    for(size_t i = 0;i < length;i++){
        Vec_push(&result, rand());
    }
    return result;
}

bool is_sorted(const Vec *data){
    if(data == NULL || data->value == NULL){
        return true;
    }

    for(size_t i = 1;i < data->length;i++){
        if(data->value[i - 1] > data->value[i]){
            return false;
        }
    }
    return true;
}

void attempt_sort(const char *name, void(*algorithm)(Vec*), const size_t length){
    const clock_t start = clock();
    Vec data = generate_unsorted(length);
    algorithm(&data);

    if(!is_sorted(&data)){
        printf("%s failed:", name);
        if(data.length == 0 || data.value == NULL){
            perror(" empty");
            return;
        }
        printf(" %lu", data.value[0]);
        for(size_t i = 1;i < data.length && i < 10;i++){
            printf(", %lu", data.value[i]);
        }
        putchar('\n');
        Vec_drop(&data);
        exit(EXIT_FAILURE);
    }

    printf("%s: passed in %lf seconds\n", name, seconds_since(start));
    Vec_drop(&data);
}

Vec generated_sorted(const size_t length){
    Vec result = Vec_new(length);
    for(size_t i = 0;i < length;i++){
        Vec_push(&result, i);
    }
    return result;
}

void attempt_search(const char *name, SearchResult(*algorithm)(const Vec*,const size_t), const size_t length){
    const clock_t start = clock();
    Vec data = generated_sorted(length);
    
    for(size_t i = 0;i < length;i++){
        SearchResult result = algorithm(&data, i);
        if(!result.found){
            printf("Failed to find %lu with %s\n", i, name);
            exit(EXIT_FAILURE);
        }else if(result.index != i){
            printf("Found %lu at the wrong index (%lu)\n", i, result.index);
            exit(EXIT_FAILURE);
        }
    }

    if(algorithm(&data, length).found){
        printf("Found non-existent value with %s\n", name);
        exit(EXIT_FAILURE);
    }

    printf("%s: passed in %lf seconds\n", name, seconds_since(start));
    Vec_drop(&data);
}

int main(){
    attempt_sort("bubble sort", bubble_sort, 30000);
    attempt_sort("insertion sort", insertion_sort, 50000);
    attempt_sort("merge sort", merge_sort, 100000000);
    attempt_sort("selection sort", selection_sort, 30000);

    attempt_search("linear search", linear_search, 50000);
    attempt_search("binary search", binary_search, 20000000);
}
