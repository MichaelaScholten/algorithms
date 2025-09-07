/// Sorts the data using bubble sort
pub fn sort<T: PartialOrd>(data: &mut [T]) {
    // Iterate through the list `data.len()` times
    for i in 0..data.len() {
        // Iterate through the list, starting 1 element after the iteration count
        for j in (i + 1..data.len()).rev() {
            // Swap the elements if in the wrong order
            if data[j - 1] > data[j] {
                data.swap(j, j - 1);
            }
        }
    }
}
