#include <iostream>
#include <functional>
#include <chrono>
#include <random>

#include "sort.hpp"

namespace chrono = std::chrono;
using chrono::steady_clock;
using chrono::seconds;
using chrono::nanoseconds;

double seconds_since(steady_clock::time_point since){
    return (steady_clock::now() - since).count() /
        (seconds(1) / nanoseconds(1));
}

std::vector<uint_fast32_t> generate_unsorted(const size_t length){
    std::minstd_rand rng;
    std::vector<size_t> numbers;
    numbers.reserve(length);
    for(size_t i = 0;i < length;i++){
        numbers.push_back(rng());
    }
    return numbers;
}

template<class T>
bool is_sorted(const std::vector<T>& data){
    for(size_t i = 1;i < data.size();i++){
        if(data[i - 1] > data[i]){
            return false;
        }
    }
    return true;
}

void attempt_sort(std::function<void(std::vector<uint_fast32_t>&)> algorithm, const size_t length){
    steady_clock::time_point start = steady_clock::now();
    std::vector<uint_fast32_t> data = generate_unsorted(length);
    algorithm(data);
    
    if(is_sorted(data)){
        std::cout << "Data is sorted\n";
    }else{
        std::cout << "Sorting failed:";
        if(data.empty()){
            std::cout << " empty\n";
            return;
        }
        std::cout << ' ' << data[0];
        for(size_t i = 1;i < data.size() && i < 10;i++){
            std::cout << ", " << data[i];
        }
        std::cout << '\n';
        exit(EXIT_FAILURE);
    }

    std::cout << seconds_since(start) << " seconds\n";
}

int main(){
    std::cout << "bubble sort\n";
    attempt_sort(bubble_sort<uint_fast32_t>, 10);

    std::cout << "insertion sort\n";
    attempt_sort(insertion_sort<uint_fast32_t>, 10);

    std::cout << "merge sort\n";
    attempt_sort(merge_sort<uint_fast32_t>, 10);

    std::cout << "selection sort\n";
    attempt_sort(selection_sort<uint_fast32_t>, 10);
}
