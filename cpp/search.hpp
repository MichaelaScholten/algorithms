#pragma once

#include <optional>
#include <vector>

template<class T>
std::optional<size_t> linear_search(const std::vector<T>& values, const T& target){
    for(size_t i = 0;i < values.size();i++){
        if(values[i] == target){
            return std::optional(i);
        }
    }
    return std::optional<size_t>();
}

template<class T>
std::optional<size_t> binary_search(const std::vector<T>& values, const T& target){
    size_t a = 0, b = values.size();
    while(b - a > 1){
        const size_t c = (a + b) / 2;
        const T& value = values[c];
        if(value < target){
            a = c;
        }else if(value > target){
            b = c;
        }else{
            return std::optional(c);
        }
    }
    return values[a] == target? std::optional(a) : std::optional<size_t>();
}
