const MOD : i64 = 1_000_000_007;

impl Solution {
  pub fn concatenated_binary(n: i32) -> i32 {
    let mut ans = 0 as i64;
    for i in 1..=n as i64 {
      let mut pw = 1;
      for d in 0..40 {
        if pw * 2 > i { break; }
        pw *= 2;
      }
      ans = (ans * pw * 2 + i as i64) % MOD;
    }
    ans as i32
  }
}
