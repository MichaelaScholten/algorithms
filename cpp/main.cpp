#include <iostream>
#include <functional>
#include <chrono>
#include <random>

#include "sort.hpp"
#include "search.hpp"

namespace chrono = std::chrono;
using chrono::steady_clock;
using chrono::seconds;
using chrono::nanoseconds;

double seconds_since(steady_clock::time_point since){
    return (double)(steady_clock::now() - since).count() /
        (seconds(1) / nanoseconds(1));
}

std::vector<uint_fast32_t> generate_unsorted(const size_t length){
    std::minstd_rand rng;
    std::vector<uint_fast32_t> numbers;
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

void attempt_sort(const std::string& name, std::function<void(std::vector<uint_fast32_t>&)> algorithm, const size_t length){
    steady_clock::time_point start = steady_clock::now();
    std::vector<uint_fast32_t> data = generate_unsorted(length);
    algorithm(data);
    
    if(!is_sorted(data)){
        std::cout << name << " failed:";
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

    std::cout << name << ": passed in " << seconds_since(start) << " seconds\n";
}

std::vector<size_t> generate_sorted(const size_t length){
    std::vector<size_t> numbers;
    numbers.reserve(length);
    for(size_t i = 0;i < length;i++){
        numbers.push_back(i);
    }
    return numbers;
}

void attempt_search(const std::string& name, std::function<std::optional<size_t>(const std::vector<size_t>&, const size_t&)> algorithm, const size_t length){
    steady_clock::time_point start = steady_clock::now();
    std::vector<size_t> data = generate_sorted(length);
    
    for(size_t i = 0;i < length;i++){
        std::optional<size_t> found = algorithm(data, i);
        if(!found.has_value()){
            std::cout << "Failed to find " << i << " with " << name << '\n';
            exit(EXIT_FAILURE);
        }else if(found.value() != i){
            std::cout << "Failed " << i << " at the wrong index (" << found.value() << ")\n";
            exit(EXIT_FAILURE);
        }
    }
    if(algorithm(data, length).has_value()){
        std::cout << "Found non-existent value with " << name << '\n';
        exit(EXIT_FAILURE);
    }

    std::cout << name << ": passed in " << seconds_since(start) << " seconds\n";
}

int main(){
    attempt_sort("bubble sort", bubble_sort<uint_fast32_t>, 30000);

    attempt_sort("insertion sort", insertion_sort<uint_fast32_t>, 60000);

    attempt_sort("merge sort", merge_sort<uint_fast32_t>, 5000000);

    attempt_sort("selection sort", selection_sort<uint_fast32_t>, 40000);

    attempt_search("linear search", linear_search<size_t>, 50000);

    attempt_search("binary search", binary_search<size_t>, 20000000);
}
