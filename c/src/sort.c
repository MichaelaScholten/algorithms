#include "sort.h"

void swap(size_t *first, size_t *second){
    if(first == NULL || second == NULL){
        return;
    }
    const size_t tmp = *first;
    *first = *second;
    *second = tmp;
}

void bubble_sort(Vec *data){
    if(data == NULL || data->value == NULL){
        return;
    }

    for(size_t i = 0;i < data->length;i++){
        for(size_t j = data->length - 1;j > i;j--){
            if(data->value[j - 1] > data->value[j]){
                swap(data->value + j - 1, data->value + j);
            }
        }
    }
}

void insertion_sort(Vec *data){
    if(data == NULL || data->value == NULL){
        return;
    }

    for(size_t i = 1;i < data->length;i++){
        for(size_t j = i;j > 0 && data->value[j - 1] > data->value[j];j--){
            swap(data->value + j - 1, data->value + j);
        }
    }
}

void merge_sort(Vec *data){
    if(data == NULL || data->value == NULL){
        return;
    }

    if(data->length == 2 && data->value[0] > data->value[1]){
        swap(data->value, data->value + 1);
        return;
    }
    if(data->length <= 2){
        return;
    }

    const size_t middle_index = data->length / 2;
    Vec left = Slice_to_vec(Slice_new(data, 0, middle_index));
    Vec right = Slice_to_vec(Slice_new(data, middle_index, data->length - middle_index));

    merge_sort(&left);
    merge_sort(&right);
    data->length = 0;

    size_t i = 0, j = 0;
    while(i < left.length && j < right.length){
        if(left.value[i] < right.value[j]){
            Vec_push(data, left.value[i++]);
        }else{
            Vec_push(data, right.value[j++]);
        }
    }
    
    while(i < left.length){
        Vec_push(data, left.value[i++]);
    }

    while(j < right.length){
        Vec_push(data, right.value[j++]);
    }
    Vec_drop(&left);
    Vec_drop(&right);
}

void selection_sort(Vec *data){
    if(data == NULL || data->value == NULL){
        return;
    }

    for(size_t i = 0;i < data->length;i++){
        size_t lowest_index = i;
        for(size_t j = i + 1;j < data->length;j++){
            if(data->value[j] < data->value[lowest_index]){
                lowest_index = j;
            }
        }

        swap(data->value + i, data->value + lowest_index);
    }
}
