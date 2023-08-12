impl Solution {
  pub fn unique_paths_with_obstacles(obstacle_grid: Vec<Vec<i32>>) -> i32 {
    let (n, m) = (obstacle_grid.len(), obstacle_grid[0].len());

    let mut d = vec![vec![0; m]; n];
    if obstacle_grid[0][0] == 0 { d[0][0] = 1; }

    for i in 0..n {
      for j in 0..m {
        if obstacle_grid[i][j] == 1 { continue; }
        if i > 0 { d[i][j] += d[i - 1][j]; }
        if j > 0 { d[i][j] += d[i][j - 1]; }
      }
    }

    d[n - 1][m - 1]
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::unique_paths_with_obstacles(vec![vec![0,0,0],vec![0,1,0],vec![0,0,0]]), 2);
  assert_eq!(Solution::unique_paths_with_obstacles(vec![vec![0,1],vec![0,0]]), 1);
  println!("OK");
}
