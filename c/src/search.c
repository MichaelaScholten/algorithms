#include "search.h"

#include <stdbool.h>

SearchResult linear_search(const Vec *values, const size_t target){
    // If the Vec doesn't exist or is empty, return that the value wasn't found
    if(values == NULL || values->value == NULL){
        return (SearchResult){
            .found = false,
            .index = 0
        };
    }

    // Iterate through the Vec
    for(size_t i = 0;i < values->length;i++){
        // If the current element is equal to the target value
        if(values->value[i] == target){
            // Return the position it was found at
            return (SearchResult){
                .found = true,
                .index = i
            };
        }
    }

    // Return that the value wasn't found
    return (SearchResult){
        .found = false,
        .index = 0
    };
}

SearchResult binary_search(const Vec *values, const size_t target){
    // If the Vec doesn't exist or is empty, return that the value wasn't found
    if(values == NULL || values->value == NULL){
        return (SearchResult){
            .found = false,
            .index = 0
        };
    }

    // Take the minimum and maximum index +1 of the Vec
    size_t a = 0, b = values->length;

    // Keep searching until there are no elements left between both indices
    while(b - a > 1){
        // take the index in the middle and the value at that index
        const size_t c = (a + b) / 2;
        const size_t value = values->value[c];

        // If the value is less that the target, make the current index the minimum.
        // If the value is greater, make it the maximum.
        // If the value is equal, return the index of the value.
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

    // If the value at index a is equal to the target, return index a.
    // Otherwise, return that the object wasn't found.
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
