impl Solution {
  fn check(stations: &Vec<usize>, r: usize, k: usize, m: usize) -> bool {
    let n = stations.len();
    let mut dt = vec![0; n];
    let (mut acc, mut cnt) = (0, 0);

    for i in 0..n {
      acc -= dt[i];

      let e = stations[i];
      if e + acc < m {
        let dif = m - (e + acc);
        acc += dif; cnt += dif;
        if i + 2 * r + 1 < n { dt[i + 2 * r + 1] += dif; }
      }
    }

    cnt <= k
  }

  pub fn max_power(stations: Vec<i32>, r: i32, k: i32) -> i64 {
    let (n, r, k) = (stations.len(), r as usize, k as usize);

    let mut pf = vec![]; pf.push(stations[0] as usize);
    for i in 1..n { pf.push(pf[i - 1] + stations[i] as usize); }

    let mut a = vec![];
    for i in 0..n {
      let mut val = pf[(n - 1).min(i + r)];
      if i >= r + 1 { val -= pf[i - r - 1]; }
      a.push(val);
    }

    let (mut left, mut right) = (0, 1e12 as usize);
    while left < right {
      let m = (left + right) / 2;
      if Self::check(&a, r, k, m) { left = m + 1; }
      else { right = m; }
    }
    (left - 1) as i64
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::max_power(vec![1,2,4,5,0],1,2), 5);
  assert_eq!(Solution::max_power(vec![4,4,4,4],0,3), 4);
  println!("OK");
}
