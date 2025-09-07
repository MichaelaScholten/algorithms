pub mod bubble;
pub mod insertion;
pub mod merge;
pub mod selection;

#[cfg(test)]
mod tests {
    use super::{bubble, insertion, merge, selection};

    /// Generates data and tries to sort it.
    fn attempt_sort(sort: impl Fn(&mut [usize]), length: usize) {
        // Generate the data
        let mut data = (0..length).rev().collect::<Vec<_>>();

        // Sort the data
        sort(&mut data);

        // Check whether it's sorted
        assert!(data.is_sorted());
    }

    /// Sort the data using bubble sort
    #[test]
    fn bubble_test() {
        attempt_sort(bubble::sort, 1_000);
    }

    /// Sort the data using insertion sort
    #[test]
    fn insertion_test() {
        attempt_sort(insertion::sort, 1_000);
    }

    /// Sort the data using merge sort
    #[test]
    fn merge_test() {
        attempt_sort(merge::sort, 1_000);
    }

    /// Sort the data using selection sort
    #[test]
    fn selection_test() {
        attempt_sort(selection::sort, 1_000);
    }
}
