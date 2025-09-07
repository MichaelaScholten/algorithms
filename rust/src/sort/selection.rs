/// Sort the data using selection sort
pub fn sort<T: PartialOrd>(data: &mut [T]) {
    // Iterate through the list `data.len()` times
    for i in 0..data.len() {
        // Use the current iteration count as initial minimum index
        let mut min_index = i;

        // Find the actual lowest index
        for j in i + 1..data.len() {
            if data[min_index] > data[j] {
                min_index = j;
            }
        }

        // Swap the lowest element with the element at the current index
        data.swap(i, min_index);
    }
}
