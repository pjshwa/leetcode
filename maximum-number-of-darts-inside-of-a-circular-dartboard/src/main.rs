impl Solution {
  pub fn num_points(darts: Vec<Vec<i32>>, r: i32) -> i32 {
    let (n, r, mut ans) = (darts.len(), r as f64, 1);
    for i in 0..n { for j in i + 1..n {
      let (x1, y1) = (darts[i][0] as f64, darts[i][1] as f64);
      let (x2, y2) = (darts[j][0] as f64, darts[j][1] as f64);

      let mut v = 4.0 * r * r;
      let sq = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
      v /= sq;
      if v < 1.0 { continue; }

      let t = (v - 1.0).sqrt() / 2.0;
      let a = (x1 + x2) / 2.0 + t * (y1 - y2);
      let b = (y1 + y2) / 2.0 + t * (x2 - x1);

      let mut cnt = 0;
      for k in 0..n {
        let (x, y) = (darts[k][0] as f64, darts[k][1] as f64);
        if (x - a) * (x - a) + (y - b) * (y - b) <= r * r + 1e-8 {
          cnt += 1;
        }
      }
      ans = ans.max(cnt);
    }}
    ans as i32
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::num_points(vec![
    vec![-2, 0], vec![2, 0], vec![0, 2], vec![0, -2]
  ], 2), 4);
  assert_eq!(Solution::num_points(vec![
    vec![-3, 0], vec![3, 0], vec![2, 6], vec![5, 4], vec![0, 9], vec![7, 8]
  ], 5), 5);
  println!("OK");
}
