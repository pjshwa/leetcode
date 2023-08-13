impl Solution {
  pub fn valid_partition(nums: Vec<i32>) -> bool {
    let n = nums.len();

    let mut dp = vec![false; n + 1]; dp[0] = true;
    for i in 2..=n {
      let (p2, p1) = (nums[i - 2], nums[i - 1]);
      if p1 == p2 { dp[i] |= dp[i - 2]; }
      if i == 2 { continue; }

      let p3 = nums[i - 3];
      if p1 == p2 && p2 == p3 { dp[i] |= dp[i - 3]; }
      if p2 == p3 + 1 && p1 == p2 + 1 { dp[i] |= dp[i - 3]; }
    }
    dp[n]
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::valid_partition(vec![4, 4, 4, 5, 6]), true);
  assert_eq!(Solution::valid_partition(vec![1, 1, 1, 2]), false);
  println!("OK");
}
