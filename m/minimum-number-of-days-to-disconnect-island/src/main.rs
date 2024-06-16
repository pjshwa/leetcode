const DX: [i32; 4] = [0, 0, 1, -1];
const DY: [i32; 4] = [1, -1, 0, 0];

impl Solution {
  fn dfs(i: usize, j: usize, grid: &Vec<Vec<i32>>, visited: &mut Vec<Vec<bool>>) {
    visited[i][j] = true;

    let (n, m) = (grid.len(), grid[0].len());
    for k in 0..4 {
      let (ni, nj) = (i as i32 + DX[k], j as i32 + DY[k]);
      if ni < 0 || ni >= n as i32 || nj < 0 || nj >= m as i32 { continue; }

      let (ni, nj) = (ni as usize, nj as usize);
      if grid[ni][nj] == 0 || visited[ni][nj] { continue; }
      Self::dfs(ni, nj, grid, visited);
    }
  }

  fn count_islands(grid: &Vec<Vec<i32>>, visited: &mut Vec<Vec<bool>>) -> i32 {
    let (n, m) = (grid.len(), grid[0].len());
    let mut ans = 0;
    for i in 0..n { for j in 0..m {
      if grid[i][j] == 0 || visited[i][j] { continue; }
      ans += 1;
      Self::dfs(i, j, grid, visited);
    }}
    ans
  }

  pub fn min_days(grid: Vec<Vec<i32>>) -> i32 {
    let (n, m) = (grid.len(), grid[0].len());

    let mut visited = vec![vec![false; m]; n];
    if Self::count_islands(&grid, &mut visited) != 1 { return 0; }

    for i in 0..n { for j in 0..m {
      let mut visited = vec![vec![false; m]; n]; visited[i][j] = true;
      if Self::count_islands(&grid, &mut visited) != 1 { return 1; }
    }}

    2
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::min_days(
    vec![vec![0, 1, 1, 0], vec![0, 1, 1, 0], vec![0, 0, 0, 0]]
  ), 2);
  assert_eq!(Solution::min_days(
    vec![vec![1, 1]]
  ), 2);
  println!("OK");
}
