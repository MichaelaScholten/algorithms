use std::mem::swap;

/// Sorts the data using merge sort
pub fn sort<T: PartialOrd + Clone>(data: &mut [T]) {
    // If there are only 2 elements and they aren't sorted, swap tem.
    // If there are more than 2 elements, sort them.
    if data.len() == 2 && !data.is_sorted() {
        data.swap(0, 1);
    } else if data.len() > 2 {
        // Split and clone the data in 2 lists
        let (a, b) = data.split_at(data.len() / 2);
        let (mut a, mut b) = (a.to_vec(), b.to_vec());

        // Sort both lists
        sort(&mut a);
        sort(&mut b);

        // Add the elements to the original list in order
        let mut i = 0;
        let mut j = 0;
        let mut k = 0;
        while i < a.len() && j < b.len() {
            if a[i] < b[j] {
                swap(&mut data[k], &mut a[i]);
                i += 1;
            } else {
                swap(&mut data[k], &mut b[j]);
                j += 1;
            }
            k += 1;
        }

        // Add the last elements to the list
        for (dst, src) in data[k..]
            .iter_mut()
            .zip(a[i..].iter_mut().chain(b[j..].iter_mut()))
        {
            swap(dst, src);
        }
    }
}
