pub fn sort<T: PartialOrd>(data: &mut [T]) {
    for i in 0..data.len() {
        for j in (i + 1..data.len()).rev() {
            if data[j - 1] > data[j] {
                data.swap(j, j - 1);
            }
        }
    }
}
