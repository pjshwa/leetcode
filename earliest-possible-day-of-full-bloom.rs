use std::cmp::Ordering;

impl Solution {
  pub fn earliest_full_bloom(plant_time: Vec<i32>, grow_time: Vec<i32>) -> i32 {
    let n = plant_time.len();
    let mut a = vec![];
    for i in 0..n {
      a.push((plant_time[i], grow_time[i]));
    }
    a.sort_by(|a, b| {
      if (a.0 + a.1).max(a.0 + b.0 + b.1) < (b.0 + b.1).max(b.0 + a.0 + a.1) {
        Ordering::Less
      } else {
        Ordering::Greater
      }
    });

    let (mut ans, mut acc) = (0, 0);
    for i in 0..n {
      ans = ans.max(acc + a[i].1);
      acc += a[i].0;
    }
    ans
  }
}
