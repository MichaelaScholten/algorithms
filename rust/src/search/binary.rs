use std::cmp::Ordering;

pub fn search<T: Ord>(data: &[T], value: &T) -> Option<usize> {
    let mut a: usize = 0;
    let mut b = data.len();
    while a.abs_diff(b) > 1 {
        let c = (a + b) / 2;
        match data[c].cmp(value) {
            Ordering::Less => a = c,
            Ordering::Equal => return Some(c),
            Ordering::Greater => b = c,
        }
    }
    let c = (a + b) / 2;
    (&data[c] == value).then_some(c)
}
