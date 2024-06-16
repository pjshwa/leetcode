const MOD: usize = 1_000_000_007;

impl Solution {
  fn pow(x: usize, y: usize) -> usize {
    let mut ans = 1;
    let (mut x, mut y) = (x, y);
    while y > 0 {
      if y & 1 == 1 {
        ans = ans * x % MOD;
      }
      x = x * x % MOD;
      y >>= 1;
    }
    ans
  }

  fn choose(n: usize, k: usize, fac: &Vec<usize>, ifac: &Vec<usize>) -> usize {
    if n < k { return 0; }
    fac[n] * ifac[k] % MOD * ifac[n - k] % MOD
  }

  fn f(n: usize, k: usize, goal: usize) -> usize {
    if n < k { return 0; }

    let mut ret = 1;
    for i in 0..k { ret = ret * (n - i) % MOD; }
    ret = ret * Self::pow(n - k, goal - k) % MOD;
    ret
  }

  pub fn num_music_playlists(n: i32, goal: i32, k: i32) -> i32 {
    let (n, goal, k) = (n as usize, goal as usize, k as usize);

    let (mut fac, mut ifac) = (vec![1 as usize; goal + 1], vec![1 as usize; goal + 1]);
    for i in 1..=goal { fac[i] = fac[i - 1] * i % MOD; }
    ifac[goal] = Self::pow(fac[goal], MOD - 2);
    for i in (1..=goal).rev() { ifac[i - 1] = ifac[i] * i % MOD; }

    let mut ans = 0;
    for c in (0..=n).rev() {
      let cur = Self::choose(n, c, &fac, &ifac) * Self::f(n - c, k, goal) % MOD;
      if c & 1 == 1 { ans = (ans + MOD - cur) % MOD; }
      else { ans = (ans + cur) % MOD; }
    }
    ans as i32
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::num_music_playlists(3, 3, 1), 6);
  assert_eq!(Solution::num_music_playlists(2, 3, 0), 6);
  assert_eq!(Solution::num_music_playlists(2, 3, 1), 2);
  println!("OK");
}
