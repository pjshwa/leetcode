const MOD: i32 = 1_000_000_007;

impl Solution {
  pub fn num_rolls_to_target(n: i32, k: i32, target: i32) -> i32 {
    let mut d = vec![vec![0; target as usize + 1]; n as usize + 1];
    d[0][0] = 1;

    for i in 1..=n as usize {
      for t in 0..=target as usize {
        for j in 1..=k as usize {
          if t >= j {
            d[i][t] = (d[i][t] + d[i - 1][t - j]) % MOD;
          }
        }
      }
    }

    d[n as usize][target as usize]
  }
}
