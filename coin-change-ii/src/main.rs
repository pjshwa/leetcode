impl Solution {
  pub fn change(amount: i32, coins: Vec<i32>) -> i32 {
    let amount = amount as usize;
    let mut dp = vec![0; amount + 1]; dp[0] = 1;

    for &c in &coins {
      let c = c as usize;
      for v in c..=amount {
        dp[v] += dp[v - c];
      }
    }

    dp[amount]
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::change(5, vec![1, 2, 5]), 4);
  assert_eq!(Solution::change(3, vec![2]), 0);
  assert_eq!(Solution::change(10, vec![10]), 1);
  println!("OK");
}
