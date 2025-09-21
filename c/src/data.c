#include "data.h"

#include <stdlib.h>
#include <string.h>

Vec Vec_new(const size_t capacity){
    // Create the Vec
    Vec result = {
        .capacity = capacity,
        .length = 0,
        .value = (size_t*)malloc(capacity * sizeof(size_t))
    };
    
    // Set the capacity to 0 on failure to allocate
    if(result.value == NULL){
        result.capacity = 0;
    }

    return result;
}

void Vec_push(Vec *self, const size_t value){
    // Return if the Vec doesn't exist
    if(self == NULL){
        return;
    }

    // If the Vec isn't allocated, allocate a new one
    if(self->capacity == 0){
        self->capacity = 1;
        self->value = (size_t*)malloc(sizeof(size_t));
    }

    // Resize the Vec if capacity has been reached
    if(self->length >= self->capacity){
        self->capacity = self->capacity * 2;
        self->value = (size_t*)realloc(self->value, self->capacity * sizeof(size_t));
    }

    // Reset the Vec and return on failure
    if(self->value == NULL){
        self->capacity = 0;
        self->length = 0;
        self->value = NULL;
        return;
    }

    // Add the value to the Vec
    self->value[self->length++] = value;
}

void Vec_drop(Vec *self){
    // Return if the Vec doesn't exist
    if(self == NULL){
        return;
    }

    // Deallocate the array if it exists
    if(self->value != NULL){
        free(self->value);
        self->value = NULL;
    }

    // Reset the capacity and length of the Vec
    self->capacity = 0;
    self->length = 0;
}

Slice Slice_new(const Vec *vec, const size_t start, const size_t length){
    // Return an empty slice if the Vec doesn't exist, the vec isn't allocated or the start of the
    // slice is after the end of the Vec.
    if(vec == NULL || vec->value == NULL || start > vec->length){
        return (Slice){ .length = 0, .value = NULL };
    }

    // Return the slice with the proper length
    return (Slice){
        .length = start + length < vec->length? length : vec->length - start,
        .value = vec->value + start
    };
}

Vec Slice_to_vec(const Slice self){
    // Return an empty vec if the slice is empty
    if(self.value == NULL){
        return (Vec){.capacity = 0, .length = 0, .value = NULL};
    }

    // Create a new Vec
    Vec result = Vec_new(self.length);

    // Add the elements to the vec if allocation was successfull
    if(result.capacity != 0){
        memcpy(result.value, self.value, self.length * sizeof(size_t));
    }
    
    return result;
}
