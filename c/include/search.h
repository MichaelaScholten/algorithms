#pragma once

#include "data.h"

typedef struct {
    bool found;
    size_t index;
} SearchResult;

SearchResult linear_search(const Vec *values, const size_t target){
    if(values == NULL || values->value == NULL){
        return (SearchResult){
            .found = false,
            .index = 0
        };
    }

    for(size_t i = 0;i < values->length;i++){
        if(values->value[i] == target){
            return (SearchResult){
                .found = true,
                .index = i
            };
        }
    }

    return (SearchResult){
        .found = false,
        .index = 0
    };
}

SearchResult binary_search(const Vec *values, const size_t target){
    if(values == NULL || values->value == NULL){
        return (SearchResult){
            .found = false,
            .index = 0
        };
    }

    size_t a = 0, b = values->length;
    while(b - a > 1){
        const size_t c = (a + b) / 2;
        const size_t value = values->value[c];
        if(value < target){
            a = c;
        }else if(value > target){
            b = c;
        }else{
            return (SearchResult){
                .found = true,
                .index = c
            };
        }
    }

    if(values->value[a] == target){
        return (SearchResult){
            .found = true,
            .index = a
        };
    }else{
        return (SearchResult){
            .found = false,
            .index = 0
        };
    }
}
