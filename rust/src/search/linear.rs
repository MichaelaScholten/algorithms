/// Searches for the requested value using linear search
pub fn search<T: PartialEq>(data: &[T], value: &T) -> Option<usize> {
    data.iter().position(|item| item == value)
}
