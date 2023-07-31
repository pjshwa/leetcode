impl Solution {
  fn rec(p: usize, l: usize, r: usize, n: usize, nums: &Vec<i32>, dp: &mut Vec<Vec<Vec<i32>>>) -> i32 {
    if l == r { return if p == 0 { nums[l] } else { -nums[l] }; }
    if dp[p][l][r] != i32::MIN { return dp[p][l][r]; }

    let mut ret = if p == 0 { i32::MIN } else { i32::MAX };
    if p == 0 {
      if l < n - 1 { ret = std::cmp::max(ret, nums[l] + Self::rec(1, l + 1, r, n, &nums, dp)); }
      if r > 0 { ret = std::cmp::max(ret, nums[r] + Self::rec(1, l, r - 1, n, &nums, dp)); }
    }
    else {
      if l < n - 1 { ret = std::cmp::min(ret, -nums[l] + Self::rec(0, l + 1, r, n, &nums, dp)); }
      if r > 0 { ret = std::cmp::min(ret, -nums[r] + Self::rec(0, l, r - 1, n, &nums, dp)); }
    }

    dp[p][l][r] = ret;
    ret
  }

  pub fn predict_the_winner(nums: Vec<i32>) -> bool {
    let n = nums.len();
    let mut dp = vec![vec![vec![i32::MIN; n]; n]; 2];

    let ans = Self::rec(0, 0, n - 1, n, &nums, &mut dp);
    ans >= 0
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::predict_the_winner(vec![1, 5, 2]), false);
  assert_eq!(Solution::predict_the_winner(vec![1, 5, 233, 7]), true);
  assert_eq!(Solution::predict_the_winner(vec![0]), true);
  println!("OK");
}
