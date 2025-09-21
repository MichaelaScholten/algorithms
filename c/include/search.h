#pragma once

#include "data.h"

/// @brief Whether the value was found and the index it was found at
typedef struct {
    bool found;
    size_t index;
} SearchResult;

/// @brief Tries to find a value in the Vec.
/// @param values The values to search through
/// @param target The value to find
/// @return Whether the value was found and the index it was found at
SearchResult linear_search(const Vec *values, const size_t target);

/// @brief Tries to find a value in the Vec.
/// @param values The values to search through
/// @param target The value to find
/// @return Whether the value was found and the index it was found at
SearchResult binary_search(const Vec *values, const size_t target);
