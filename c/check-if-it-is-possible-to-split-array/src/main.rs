impl Solution {
  pub fn can_split_array(nums: Vec<i32>, m: i32) -> bool {
    let n = nums.len();
    if n <= 2 { return true; }

    for i in 1..n {
      if nums[i] + nums[i - 1] >= m { return true; }
    }
    false
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::can_split_array(vec![2, 2, 1], 4), true);
  assert_eq!(Solution::can_split_array(vec![2, 1, 3], 5), false);
  assert_eq!(Solution::can_split_array(vec![2, 3, 3, 2, 3], 6), true);
  println!("OK");
}
