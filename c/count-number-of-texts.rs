const MAX : usize = 100_000;
const MOD : i64 = 1_000_000_007;

impl Solution {
  pub fn count_texts(pressed_keys: String) -> i32 {
    let mut d3 = vec![0; MAX + 1];
    let mut d4 = vec![0; MAX + 1];
    d3[0] = 1; d4[0] = 1;

    for i in 1..=MAX {
      for j in 1..=3 {
        if i >= j {
          d3[i] += d3[i - j];
          d3[i] %= MOD;
        }
      }
      for j in 1..=4 {
        if i >= j {
          d4[i] += d4[i - j];
          d4[i] %= MOD;
        }
      }
    }

    let s = pressed_keys + " ";
    let (mut prev, mut streak, mut ans) = (' ', 0, 1);
    for c in s.chars() {
      if c == prev { streak += 1; }
      else {
        if prev == '7' || prev == '9' {
          ans *= d4[streak];
          ans %= MOD;
        }
        else {
          ans *= d3[streak];
          ans %= MOD;
        }
        prev = c;
        streak = 1;
      }
    }
    ans as i32
  }
}
