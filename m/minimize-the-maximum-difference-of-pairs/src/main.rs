impl Solution {
  pub fn minimize_max(nums: Vec<i32>, p: i32) -> i32 {
    let n = nums.len();
    let mut nums = nums; nums.sort();

    let (mut l, mut r) = (0, nums[n - 1]);
    while l < r {
      let m = (l + r) / 2;

      let (mut i, mut cnt) = (1, 0);
      while i < n {
        let dif = nums[i] - nums[i - 1];
        if dif <= m {
          cnt += 1;
          i += 2;
        }
        else { i += 1; }
      }

      if cnt >= p { r = m; }
      else { l = m + 1; }
    }
    l
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::minimize_max(vec![10,1,2,7,1,3], 2), 1);
  assert_eq!(Solution::minimize_max(vec![4,2,1,2], 1), 0);
  println!("OK");
}
