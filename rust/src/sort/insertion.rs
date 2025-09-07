pub fn sort<T: PartialOrd>(data: &mut [T]) {
    for i in 1..data.len() {
        for j in (i..data.len()).rev() {
            if data[j - 1] > data[j] {
                data.swap(j - 1, j);
            }
        }
    }
}
