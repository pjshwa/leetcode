impl Solution {
  fn rec(nums: &Vec<i32>, used: &mut Vec<bool>, cur: &mut Vec<usize>, ans: &mut Vec<Vec<i32>>) {
    if cur.len() == nums.len() {
      ans.push(cur.iter().map(|&i| nums[i]).collect());
      return;
    }

    for i in 0..nums.len() {
      if used[i] { continue; }
      used[i] = true;
      cur.push(i);
      Self::rec(nums, used, cur, ans);
      cur.pop();
      used[i] = false;
    }
  }

  pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
    let mut ans: Vec<Vec<i32>> = Vec::new();
    let mut cur: Vec<usize> = Vec::new();

    let n = nums.len();
    let mut used = vec![false; n];
    Self::rec(&nums, &mut used, &mut cur, &mut ans);
    ans
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::permute(vec![1, 2, 3]), vec![
    vec![1, 2, 3],
    vec![1, 3, 2],
    vec![2, 1, 3],
    vec![2, 3, 1],
    vec![3, 1, 2],
    vec![3, 2, 1],
  ]);
  assert_eq!(Solution::permute(vec![0, 1]), vec![
    vec![0, 1],
    vec![1, 0],
  ]);
  assert_eq!(Solution::permute(vec![1]), vec![
    vec![1],
  ]);
  println!("OK");
}
