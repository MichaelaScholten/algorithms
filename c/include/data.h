#pragma once

#include <stddef.h>

/// @brief A dynamically allocated array
typedef struct {
    // A pointer to the array
    size_t *value;

    // The capacity of the array
    size_t capacity;

    // The number of values stored in the array
    size_t length;
} Vec;

/// @brief Creates a new Vec
/// @param capacity The initial capacity of the Vec
/// @return The created Vec (value and capacity will be NULL on failure)
Vec Vec_new(const size_t capacity);

/// @brief Adds an element to the Vec
/// @param self The Vec to add the value to
/// @param value The value to add
void Vec_push(Vec *self, const size_t value);

/// @brief Deallocates the array
/// @param self The Vec to reset
void Vec_drop(Vec *self);

/// @brief A slice of a Vec
typedef struct {
    // A part of the Vec
    size_t *value;

    // The length of that slice
    size_t length;
} Slice;

/// @brief Takes a new slice from a Vec
/// @param vec the Vec to start a slice from
/// @param start the index of the Vec to start the slice from
/// @param length the maximum length of the slice
/// @return the new slice or an empty slice if the start is out of bounds
Slice Slice_new(const Vec *vec, const size_t start, const size_t length);

/// @brief Creates a new Vec and assigns it the values of the slice
/// @param self the Slice to turn into a Vec
/// @return the resulting Vec or NULL on failure creating the Vec
Vec Slice_to_vec(const Slice self);
