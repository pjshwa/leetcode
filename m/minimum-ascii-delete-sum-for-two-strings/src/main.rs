impl Solution {
  pub fn minimum_delete_sum(s1: String, s2: String) -> i32 {
    let mut tot = 0;
    for c in s1.chars() { tot += c as i32; }
    for c in s2.chars() { tot += c as i32; }

    let (n, m) = (s1.len(), s2.len());
    let mut dp = vec![vec![0; m + 1]; n + 1];

    let s1 = s1.as_bytes();
    let s2 = s2.as_bytes();
    for i in 0..n {
      for j in 0..m {
        if s1[i] == s2[j] {
          dp[i + 1][j + 1] = dp[i][j] + s1[i] as i32;
        }
        else {
          dp[i + 1][j + 1] = std::cmp::max(dp[i + 1][j], dp[i][j + 1]);
        }
      }
    }

    tot - 2 * dp[n][m]
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::minimum_delete_sum("sea".to_string(), "eat".to_string()), 231);
  assert_eq!(Solution::minimum_delete_sum("delete".to_string(), "leet".to_string()), 403);
  println!("OK");
}
