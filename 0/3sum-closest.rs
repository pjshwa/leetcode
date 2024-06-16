impl Solution {
  pub fn three_sum_closest(nums: Vec<i32>, target: i32) -> i32 {
    let mut a = nums; a.sort();
    let n = a.len();

    let mut ret = a[0] + a[1] + a[2];
    for i in 1..(n - 1) {
      let (mut l, mut r) = (0, n - 1);
      while l < i && i < r {
        let cur = a[l] + a[i] + a[r];
        let diff = cur - target;
        if diff.abs() < (ret - target).abs() { ret = cur; }

        if diff == 0 { return ret; }
        else if diff < 0 { l += 1; }
        else { r -= 1; }
      }
    }
    ret
  }
}
