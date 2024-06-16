use std::collections::HashSet;

impl Solution {
  fn rec(l: usize, r: usize, dp: &mut Vec<Vec<i32>>, s: &Vec<char>) -> i32 {
    if l > r { 0 }
    else if dp[l][r] != -1 { dp[l][r] }
    else {
      let mut set = HashSet::new();
      for i in l..=r { set.insert(s[i]); }
      if set.len() == 1 {
        dp[l][r] = 1;
        return 1;
      }

      let mut ans = 1 + Self::rec(l + 1, r, dp, s);
      for i in l + 1..=r {
        if s[i] != s[l] { continue; }
        ans = std::cmp::min(ans, Self::rec(l, i - 1, dp, s) + Self::rec(i + 1, r, dp, s));
      }
      dp[l][r] = ans;
      ans
    }
  }

  pub fn strange_printer(s: String) -> i32 {
    let n = s.len();
    let mut dp = vec![vec![-1; n]; n];
    Self::rec(0, n - 1, &mut dp, &s.chars().collect())
  }
}

struct Solution;
fn main() {
  assert_eq!(2, Solution::strange_printer("aaabbb".to_string()));
  assert_eq!(2, Solution::strange_printer("aba".to_string()));
  assert_eq!(15, Solution::strange_printer("dddccbdbababaddcbcaabdbdddcccddbbaabddb".to_string()));
  println!("OK");
}
