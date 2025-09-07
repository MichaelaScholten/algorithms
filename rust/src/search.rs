pub mod binary;
pub mod linear;

#[cfg(test)]
mod tests {
    use crate::search::binary;

    use super::linear;

    fn attempt_search(algorithm: impl Fn(&[usize], &usize) -> Option<usize>, length: usize) {
        let data = (0..length).collect::<Vec<_>>();
        for i in 0..length {
            assert_eq!(algorithm(&data, &i), Some(i));
        }
        assert!(algorithm(&data, &length).is_none());
    }

    #[test]
    fn linear_test() {
        attempt_search(linear::search, 10_000);
    }

    #[test]
    fn binary_test() {
        attempt_search(binary::search, 10_000);
    }
}
