#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#include "data.h"
#include "sort.h"

double seconds_since(const clock_t since){
    return (double)(clock() - since) / CLOCKS_PER_SEC;
}

Vec generate_sorted(const size_t length){
    srand(clock() + time(NULL));
    Vec result = Vec_new(length);
    for(size_t i = 0;i < length;i++){
        Vec_push(&result, i);
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
    clock_t start = clock();
    Vec data = generate_sorted(length);
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

int main(){
    attempt_sort("bubble sort", bubble_sort, 50000);
    attempt_sort("insertion sort", insertion_sort, 200000000);
    attempt_sort("merge sort", merge_sort, 200000000);
    attempt_sort("selection sort", selection_sort, 30000);
}
