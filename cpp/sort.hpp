#pragma once

#include <iostream>
#include <vector>

template<class T>
void swap(T& first, T& second){
    T tmp(std::move(first));
    first = std::move(second);
    second = std::move(tmp);
}

template<class T>
void bubble_sort(std::vector<T>& data){
    for(size_t i = 0;i < data.size();i++){
        for(size_t j = data.size() - 1;j > i;j--){
            if(data[j - 1] > data[j]){
                swap(data[j - 1], data[j]);
            }
        }
    }
}

template<class T>
void insertion_sort(std::vector<T>& data){
    for(size_t i = 1;i < data.size();i++){
        for(size_t j = i;j > 0 && data[j - 1] > data[j];j--){
            swap(data[j - 1], data[j]);
        }
    }
}

template<class T>
void extend_from(std::vector<T>& target, std::vector<T>& source, const size_t start){
    for(size_t i = start;i < source.size();i++){
        target.push_back(std::move(source[i]));
    }
}

template<class T>
void merge_sort(std::vector<T>& data){
    if(data.size() == 2 && data[0] > data[1]){
        swap(data[0], data[1]);
        return;
    }
    if(data.size() <= 2){
        return;
    }

    std::vector<T> left, right;
    const size_t middle_index = data.size() / 2;
    left.reserve(middle_index);
    right.reserve(data.size() - middle_index);

    for(size_t i = 0;i < middle_index;i++){
        left.push_back(std::move(data[i]));
    }
    extend_from(right, data, middle_index);
    data.clear();

    merge_sort(left);
    merge_sort(right);

    size_t i = 0, j = 0;
    while(i < left.size() && j < right.size()){
        if(left[i] < right[j]){
            data.push_back(std::move(left[i++]));
        }else{
            data.push_back(std::move(right[j++]));
        }
    }

    extend_from(data, left, i);
    extend_from(data, right, j);
}

template<class T>
void selection_sort(std::vector<T>& data){
    for(size_t i = 0;i < data.size();i++){
        size_t lowest_index = i;
        for(size_t j = i + 1;j < data.size();j++){
            if(data[j] < data[lowest_index]){
                lowest_index = j;
            }
        }

        swap(data[i], data[lowest_index]);
    }
}
