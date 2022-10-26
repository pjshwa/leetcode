use std::collections::HashSet;

impl Solution {
  pub fn check_subarray_sum(nums: Vec<i32>, k: i32) -> bool {
    let mut s = HashSet::new();
    let (mut l1, mut run) = (0, 0);
    for num in nums {
      run = (run + num) % k;
      if s.contains(&run) {
        return true;
      }

      s.insert(l1);
      l1 = run;
    }
    false
  }
}
