#include "data.h"

#include <stdlib.h>
#include <string.h>

Vec Vec_new(const size_t capacity){
    Vec result = {
        .capacity = capacity,
        .length = 0,
        .value = (size_t*)malloc(capacity * sizeof(size_t))
    };
    if(result.value == NULL){
        result.capacity = 0;
    }
    return result;
}

void Vec_push(Vec *self, const size_t value){
    if(self == NULL){
        return;
    }
    if(self->length >= self->capacity){
        self->capacity *= 2;
        self->value = realloc(self->value, self->capacity * sizeof(size_t));
    }
    if(self->value == NULL){
        self->capacity = 0;
        self->length = 0;
        self->value = NULL;
    }
    self->value[self->length++] = value;
}

size_t Vec_get(Vec *self, const size_t index){
    if(self == NULL || self->length <= index){
        return 0;
    }
    return self->value[index];
}

size_t* Vec_get_mut(Vec *self, const size_t index){
    if(self == NULL || self->length <= index){
        return 0;
    }
    return self->value + index;
}

void Vec_drop(Vec *self){
    if(self == NULL){
        return;
    }
    if(self->value != NULL){
        free(self->value);
        self->value = NULL;
    }
    self->capacity = 0;
    self->length = 0;
}

Slice Slice_new(const Vec *vec, const size_t start, const size_t length){
    if(vec == NULL || vec->value == NULL || start > vec->length){
        return (Slice){ .length = 0, .value = NULL };
    }
    return (Slice){
        .length = start + length < vec->length? length : vec->length - start,
        .value = vec->value + start
    };
}

Vec Slice_to_vec(const Slice self){
    if(self.value == NULL){
        return (Vec){.capacity = 0, .length = 0, .value = NULL};
    }
    Vec result = Vec_new(self.length);
    if(result.capacity != 0){
        memcpy(result.value, self.value, self.length * sizeof(size_t));
    }
    return result;
}
