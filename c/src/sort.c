#include "sort.h"

/// @brief Swaps the elements
/// @param first the first value to swap with
/// @param second the second value to swap
void swap(size_t *first, size_t *second){
    // Return if either of the pointers is NULL
    if(first == NULL || second == NULL){
        return;
    }

    // Swap the values
    const size_t tmp = *first;
    *first = *second;
    *second = tmp;
}

void bubble_sort(Vec *data){
    // Return if the Vec doesn't exist or is empty
    if(data == NULL || data->value == NULL){
        return;
    }

    // Iterate through the array
    for(size_t i = 0;i < data->length;i++){
        // Iterate through the array, backwards ending at `i`
        for(size_t j = data->length - 1;j > i;j--){
            // Swap the values if in the wrong order
            if(data->value[j - 1] > data->value[j]){
                swap(data->value + j - 1, data->value + j);
            }
        }
    }
}

void insertion_sort(Vec *data){
    // Return if the Vec doesn't exist or is empty
    if(data == NULL || data->value == NULL){
        return;
    }

    // Iterate through the vector
    for(size_t i = 1;i < data->length;i++){
        // Iterate from i to the start of the Vec until the value is in the right position
        for(size_t j = i;j > 0 && data->value[j - 1] > data->value[j];j--){
            // Swap the values
            swap(data->value + j - 1, data->value + j);
        }
    }
}

void merge_sort(Vec *data){
    // Return if the Vec doesn't exist or is empty
    if(data == NULL || data->value == NULL){
        return;
    }

    // If the Vec is 2 elements long and the values are in the wrong order, swap them
    if(data->length == 2 && data->value[0] > data->value[1]){
        swap(data->value, data->value + 1);
        return;
    }

    // Return if the Vec contains 2 values or less
    if(data->length <= 2){
        return;
    }

    // Split the vec in half
    const size_t middle_index = data->length / 2;
    Vec left = Slice_to_vec(Slice_new(data, 0, middle_index));
    Vec right = Slice_to_vec(Slice_new(data, middle_index, data->length - middle_index));

    // Sort both halves
    merge_sort(&left);
    merge_sort(&right);
    data->length = 0;

    // Merge both halves into the full data vec
    size_t i = 0, j = 0;
    while(i < left.length && j < right.length){
        if(left.value[i] < right.value[j]){
            Vec_push(data, left.value[i++]);
        }else{
            Vec_push(data, right.value[j++]);
        }
    }
    
    // Add the last values of left to data
    while(i < left.length){
        Vec_push(data, left.value[i++]);
    }

    // Add the last values of right to data
    while(j < right.length){
        Vec_push(data, right.value[j++]);
    }

    // Drop the left and right half copies of the data
    Vec_drop(&left);
    Vec_drop(&right);
}

void selection_sort(Vec *data){
    // Return if the Vec doesn't exist or is empty
    if(data == NULL || data->value == NULL){
        return;
    }

    // Iterate through the Vec
    for(size_t i = 0;i < data->length;i++){
        // Find the index of the lowest value
        size_t lowest_index = i;
        for(size_t j = i + 1;j < data->length;j++){
            if(data->value[j] < data->value[lowest_index]){
                lowest_index = j;
            }
        }

        // Swap the value at the current index with the lowest value
        swap(data->value + i, data->value + lowest_index);
    }
}
