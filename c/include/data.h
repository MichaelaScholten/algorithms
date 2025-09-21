#pragma once

#include <stddef.h>

typedef struct {
    size_t *value;
    size_t capacity;
    size_t length;
} Vec;

Vec Vec_new(const size_t capacity);

void Vec_push(Vec *self, const size_t value);

size_t Vec_get(Vec *self, const size_t index);

size_t* Vec_get_mut(Vec *self, const size_t index);

void Vec_drop(Vec *self);

typedef struct {
    size_t *value;
    size_t length;
} Slice;

Slice Slice_new(const Vec *vec, const size_t start, const size_t length);

Vec Slice_to_vec(const Slice self);
