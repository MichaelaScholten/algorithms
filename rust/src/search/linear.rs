pub fn search<T: PartialEq>(data: &[T], value: &T) -> Option<usize> {
    data.iter().position(|item| item == value)
}
