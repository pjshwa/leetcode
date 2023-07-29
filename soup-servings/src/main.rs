impl Solution {
  pub fn soup_servings(n: i32) -> f64 {
    if n < 5000 {
      let n = n as usize;
      let mut dp = vec![vec![0.0; n as usize + 1]; n as usize + 1];
      dp[0][0] = 1.0;

      let da: Vec<usize> = vec![100, 75, 50, 25];
      let db: Vec<usize> = vec![0, 25, 50, 75];

      for i in 0..n {
        for j in 0..n {
          for k in 0..4 {
            let ni = std::cmp::min(n, i + da[k]);
            let nj = std::cmp::min(n, j + db[k]);

            dp[ni][nj] += dp[i][j] * 0.25;
          }
        }
      }

      let mut ans = dp[n][n] * 0.5;
      for j in 0..n { ans += dp[n][j]; }
      ans
    }
    else { 1.0 }
  }
}

struct Solution;
fn main() {
  assert_eq!(0.625, Solution::soup_servings(50));
  assert_eq!(0.71875, Solution::soup_servings(100));
  println!("OK");
}
