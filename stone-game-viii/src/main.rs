impl Solution {
  fn rec(p: usize, i: usize, n: usize, stones_pf: &Vec<i32>, dp: &mut Vec<Vec<i32>>) -> i32 {
    if i == n - 1 { return if p == 0 { stones_pf[i] } else { -stones_pf[i] }; }
    if dp[p][i] != i32::MIN { return dp[p][i]; }

    let ret;
    if p == 0 {
      ret = std::cmp::max(
        Self::rec(0, i + 1, n, stones_pf, dp),
        stones_pf[i] + Self::rec(1, i + 1, n, stones_pf, dp)
      );
    }
    else {
      ret = std::cmp::min(
        Self::rec(1, i + 1, n, stones_pf, dp),
        -stones_pf[i] + Self::rec(0, i + 1, n, stones_pf, dp)
      );
    }

    dp[p][i] = ret;
    ret
  }

  pub fn stone_game_viii(stones: Vec<i32>) -> i32 {
    let n = stones.len();

    let mut stones_pf = vec![0; n];
    stones_pf[0] = stones[0];
    for i in 1..n { stones_pf[i] = stones_pf[i - 1] + stones[i]; }

    let mut dp = vec![vec![i32::MIN; n]; 2];
    Self::rec(0, 1, n, &stones_pf, &mut dp)
  }
}

struct Solution;

#[cfg(test)]
mod tests {
  use super::*;

  #[test]
  fn test() {
    assert_eq!(Solution::stone_game_viii(vec![-1, 2, -3, 4, -5]), 5);
    assert_eq!(Solution::stone_game_viii(vec![7,-6,5,10,5,-2,-6]), 13);
    assert_eq!(Solution::stone_game_viii(vec![-10,-12]), -22);
  }
}
