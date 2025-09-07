pub mod bubble;

#[cfg(test)]
mod tests {
    use crate::sort::bubble;

    fn attempt_sort(sort: impl Fn(&mut [usize]), length: usize) {
        let mut data = (0..length).rev().collect::<Vec<usize>>();
        sort(&mut data);
        assert!(data.is_sorted());
    }

    #[test]
    fn bubble_test() {
        attempt_sort(bubble::sort, 1_000);
    }
}
