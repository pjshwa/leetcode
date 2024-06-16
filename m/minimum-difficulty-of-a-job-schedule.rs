impl Solution {
  pub fn min_difficulty(job_difficulty: Vec<i32>, d: i32) -> i32 {
    let n = job_difficulty.len();

    let div = d as usize;
    let mut d = vec![vec![i32::MAX; div + 1]; n + 1];
    d[0][0] = 0;

    for i in 1..=n { for j in 0..div {
      let mut max = 0;
      for k in (0..i).rev() {
        max = std::cmp::max(max, job_difficulty[k]);
        if d[k][j] < i32::MAX {
          d[i][j + 1] = std::cmp::min(d[i][j + 1], d[k][j] + max);
        }
      }
    }}

    if d[n][div] == i32::MAX { -1 } else { d[n][div] }
  }
}
