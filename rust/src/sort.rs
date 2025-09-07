pub mod bubble;
pub mod insertion;

#[cfg(test)]
mod tests {
    use crate::sort::{bubble, insertion};

    fn attempt_sort(sort: impl Fn(&mut [usize]), length: usize) {
        let mut data = (0..length).rev().collect::<Vec<usize>>();
        sort(&mut data);
        assert!(data.is_sorted());
    }

    #[test]
    fn bubble_test() {
        attempt_sort(bubble::sort, 1_000);
    }

    #[test]
    fn insertion_test() {
        attempt_sort(insertion::sort, 1_000);
    }
}
