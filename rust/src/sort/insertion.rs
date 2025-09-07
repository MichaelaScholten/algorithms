/// Sorts the data using insertion sort
pub fn sort<T: PartialOrd>(data: &mut [T]) {
    // Iterate through the list `data.len() - 1` times
    for i in 1..data.len() {
        // Iterate through the list, using the iteration count as start index
        for j in (i..data.len()).rev() {
            // Swap the elements if in the wrong order
            if data[j - 1] > data[j] {
                data.swap(j - 1, j);
            }
        }
    }
}
