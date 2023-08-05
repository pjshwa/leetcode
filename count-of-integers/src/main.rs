const MOD: i32 = 1_000_000_007;

impl Solution {
  fn rec(
    num: &Vec<i32>,
    i: usize,
    s: usize,
    f: usize,
    min_sum: usize,
    max_sum: usize,
    dp: &mut Vec<Vec<Vec<i32>>>
  ) -> i32 {
    if dp[i][s][f] != -1 { return dp[i][s][f]; }
    if i == num.len() {
      dp[i][s][f] = if s >= min_sum && s <= max_sum { 1 } else { 0 };
      return dp[i][s][f];
    }

    let mut res = 0;
    for c in 0..10 {
      if f == 1 && c > num[i] { break; }

      let nf = if f == 1 && c == num[i] { 1 } else { 0 };
      res += Self::rec(num, i + 1, s + c as usize, nf, min_sum, max_sum, dp);
      res %= MOD;
    }

    dp[i][s][f] = res;
    res
  }

  pub fn count(num1: String, num2: String, min_sum: i32, max_sum: i32) -> i32 {
    let num1 = num1.chars().map(|c| c.to_digit(10).unwrap() as i32).collect::<Vec<_>>();
    let num2 = num2.chars().map(|c| c.to_digit(10).unwrap() as i32).collect::<Vec<_>>();

    let mut dp = vec![vec![vec![-1; 2]; 401]; num1.len() + 1];
    let res1 = Self::rec(&num1, 0, 0, 1, min_sum as usize, max_sum as usize, &mut dp);

    let mut dp = vec![vec![vec![-1; 2]; 401]; num2.len() + 1];
    let res2 = Self::rec(&num2, 0, 0, 1, min_sum as usize, max_sum as usize, &mut dp);

    let mut ans = (res2 - res1 + MOD) % MOD;
    let num1_sum = num1.iter().sum::<i32>();
    if num1_sum >= min_sum && num1_sum <= max_sum { ans = (ans + 1) % MOD; }

    ans
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::count("1".to_string(), "12".to_string(), 1, 8), 11);
  assert_eq!(Solution::count("1".to_string(), "5".to_string(), 1, 5), 5);
  println!("OK");
}
