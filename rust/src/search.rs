pub mod binary;
pub mod linear;

#[cfg(test)]
mod tests {
    use crate::search::binary;

    use super::linear;

    /// Generates a list of numbers and tries to find every element in it.
    fn attempt_search(algorithm: impl Fn(&[usize], &usize) -> Option<usize>, length: usize) {
        // Generate the list of numbers
        let data = (0..length).collect::<Vec<_>>();

        // Make sure the algorithm can find every number in the list
        for i in 0..length {
            assert_eq!(algorithm(&data, &i), Some(i));
        }

        // Make sure it doesn't find an element just outside the list
        assert!(algorithm(&data, &length).is_none());
    }

    /// Tests whether linear search works.
    #[test]
    fn linear_test() {
        attempt_search(linear::search, 10_000);
    }

    /// Tests whether binary search works.
    #[test]
    fn binary_test() {
        attempt_search(binary::search, 10_000);
    }
}
