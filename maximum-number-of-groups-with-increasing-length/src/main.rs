impl Solution {
  fn check(g: i32, usage_limits: &Vec<i32>) -> bool {
    let mut defi: i64 = 0;
    let n = usage_limits.len();
    let l = g as usize;

    for i in 0..n {
      let need = std::cmp::max(0, (l - i) as i32);
      if usage_limits[i] < need { defi += (need - usage_limits[i]) as i64; }
      else {
        let used = std::cmp::min((usage_limits[i] - need) as i64, defi);
        defi -= used;
      }
    }
    defi == 0
  }

  pub fn max_increasing_groups(mut usage_limits: Vec<i32>) -> i32 {
    let n = usage_limits.len() as i32;
    usage_limits.sort_by(|a, b| b.cmp(a));

    let (mut l, mut r) = (1, n + 1);
    while l < r {
      let m = (l + r) / 2;
      if Self::check(m, &usage_limits) { l = m + 1; }
      else { r = m; }
    }
    l - 1
  }
}

struct Solution;
fn main() {
  {
    let usage_limits = vec![1, 2, 5];
    let result = Solution::max_increasing_groups(usage_limits);
    assert_eq!(result, 3);
  }
  {
    let usage_limits = vec![2, 1, 2];
    let result = Solution::max_increasing_groups(usage_limits);
    assert_eq!(result, 2);
  }
  {
    let usage_limits = vec![1, 1];
    let result = Solution::max_increasing_groups(usage_limits);
    assert_eq!(result, 1);
  }

  println!("OK");
}
