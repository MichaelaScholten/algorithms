pub fn sort<T: PartialOrd>(data: &mut [T]) {
    for i in 0..data.len() {
        let mut min_index = i;
        for j in i + 1..data.len() {
            if data[min_index] > data[j] {
                min_index = j;
            }
        }
        data.swap(i, min_index);
    }
}
