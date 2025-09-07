use std::cmp::Ordering;

/// Search data with the binary search algorithm
pub fn search<T: Ord>(data: &[T], value: &T) -> Option<usize> {
    // Set the range of items to search in
    let mut a: usize = 0;
    let mut b = data.len();

    // Keep searching until the element is found or the range is shorter than 2 elements.
    // This prevents infinite loops
    while a.abs_diff(b) > 1 {
        // Calculate the element in the middle of the range
        let c = (a + b) / 2;

        // Compare the value at the middle of the range to the requested value
        match data[c].cmp(value) {
            // If the current value is less, update the start of the range
            Ordering::Less => a = c,

            // If the current value is the requested value, return its index
            Ordering::Equal => return Some(c),

            // If the current value is greater, update the end of the range
            Ordering::Greater => b = c,
        }
    }

    // Return the index at the start of the range if it's the requested value.
    // Return none otherwise.
    (&data[a] == value).then_some(a)
}
