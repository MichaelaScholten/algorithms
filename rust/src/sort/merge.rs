use std::mem::swap;

pub fn sort<T: PartialOrd + Clone>(data: &mut [T]) {
    if data.len() == 2 && !data.is_sorted() {
        data.swap(0, 1);
    } else if data.len() > 2 {
        let (a, b) = data.split_at(data.len() / 2);
        let (mut a, mut b) = (a.to_vec(), b.to_vec());
        sort(&mut a);
        sort(&mut b);

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
        for (dst, src) in data[k..]
            .iter_mut()
            .zip(a[i..].iter_mut().chain(b[j..].iter_mut()))
        {
            swap(dst, src);
        }
    }
}
