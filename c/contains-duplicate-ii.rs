use std::collections::HashMap;

impl Solution {
  pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
    let mut m = HashMap::new();
    let (n, k) = (nums.len(), (k + 1) as usize);

    for i in 0..k {
      if i >= n { break; }
      if m.contains_key(&nums[i]) { return true; }
      m.insert(nums[i], i);
    }

    for i in k..n {
      m.remove(&nums[i - k]);
      if m.contains_key(&nums[i]) { return true; }
      m.insert(nums[i], i);
    }

    false
  }
}
