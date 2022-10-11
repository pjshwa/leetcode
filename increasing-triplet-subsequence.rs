impl Solution {
  pub fn increasing_triplet(nums: Vec<i32>) -> bool {
    let n = nums.len();
    let mut l = vec![i32::MAX; n]; l[0] = nums[0];
    let mut r = vec![i32::MIN; n]; r[n - 1] = nums[n - 1];

    for i in 1..n { l[i] = l[i - 1].min(nums[i]); }
    for i in (0..n - 1).rev() { r[i] = r[i + 1].max(nums[i]); }

    for i in 1..n - 1 {
      if l[i - 1] < nums[i] && nums[i] < r[i + 1] { return true; }
    }
    false
  }
}
