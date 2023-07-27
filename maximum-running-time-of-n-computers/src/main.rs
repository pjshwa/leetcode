impl Solution {
  fn check(n: i32, m: i64, batteries: &Vec<i32>) -> bool {
    let mut defi = 0 as i64;
    for i in 0..n as usize {
      if (batteries[i] as i64) < m { defi += m - batteries[i] as i64; }
    }
    for i in n as usize..batteries.len() { defi -= batteries[i] as i64; }
    defi <= 0
  }

  pub fn max_run_time(n: i32, mut batteries: Vec<i32>) -> i64 {
    batteries.sort_by(|a, b| b.cmp(a));

    let mut sum = 0 as i64;
    for b in &batteries { sum += *b as i64; }

    let (mut l, mut r) = (1 as i64, sum + 1);
    while l < r {
      let m = (l + r) / 2;
      if Self::check(n, m, &batteries) { l = m + 1; }
      else { r = m; }
    }
    l - 1
  }
}

struct Solution;

#[cfg(test)]
mod tests {
  use super::*;

  #[test]
  fn test_1() {
    assert_eq!(Solution::max_run_time(2, vec![3, 3, 3]), 4);
    assert_eq!(Solution::max_run_time(2, vec![1, 1, 1, 1]), 2);
  }
}
