impl Solution {
  pub fn minimum_time(s: String) -> i32 {
    let n = s.len();
    let mut dp = vec![0; n + 1];

    let s = s.chars().collect::<Vec<char>>();
    for i in 1..=n {
      let f = if s[i - 1] == '0' { 0 } else { 2 };
      dp[i] = i.min(dp[i - 1] + f);
    }

    let mut ans = dp[n];
    for r in (1..=n).rev() {
      ans = ans.min(dp[r - 1] + n - r + 1);
    }
    ans as i32
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::minimum_time("1100101".to_string()), 5);
  assert_eq!(Solution::minimum_time("0010".to_string()), 2);
  println!("OK");
}
