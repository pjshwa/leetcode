use std::collections::VecDeque;
const INF: i32 = 0x3f3f3f3f;
const DX: [i32; 4] = [0, 0, 1, -1];
const DY: [i32; 4] = [1, -1, 0, 0];

impl Solution {
  fn check(p: i32, grid: &Vec<Vec<i32>>, fdist: &Vec<Vec<i32>>) -> bool {
    let (n, m) = (grid.len(), grid[0].len());

    let mut cdist = vec![vec![INF; m]; n];
    let mut q = VecDeque::new();
    q.push_back((0, 0)); cdist[0][0] = p;

    while let Some((x, y)) = q.pop_front() {
      for k in 0..4 {
        let (nx, ny) = (x + DX[k], y + DY[k]);
        if nx < 0 || nx >= n as i32 || ny < 0 || ny >= m as i32 { continue; }

        let (nx, ny, x, y) = (nx as usize, ny as usize, x as usize, y as usize);
        if grid[nx][ny] == 2 { continue; }
        if fdist[nx][ny] < cdist[x][y] + 1 { continue; }

        if nx == n - 1 && ny == m - 1 { return true; }
        if fdist[nx][ny] == cdist[x][y] + 1 { continue; }

        if cdist[nx][ny] > cdist[x][y] + 1 {
          cdist[nx][ny] = cdist[x][y] + 1;
          q.push_back((nx as i32, ny as i32));
        }
      }
    }

    false
  }

  pub fn maximum_minutes(grid: Vec<Vec<i32>>) -> i32 {
    let (n, m) = (grid.len(), grid[0].len());

    let mut fdist = vec![vec![INF; m]; n];
    {
      let mut q = VecDeque::new();
      for i in 0..n { for j in 0..m {
        if grid[i][j] == 1 {
          fdist[i][j] = 0;
          q.push_back((i as i32, j as i32));
        }
      }}

      while let Some((x, y)) = q.pop_front() {
        for k in 0..4 {
          let (nx, ny) = (x + DX[k], y + DY[k]);
          if nx < 0 || nx >= n as i32 || ny < 0 || ny >= m as i32 { continue; }

          let (nx, ny, x, y) = (nx as usize, ny as usize, x as usize, y as usize);
          if grid[nx][ny] == 2 { continue; }
          if fdist[nx][ny] > fdist[x][y] + 1 {
            fdist[nx][ny] = fdist[x][y] + 1;
            q.push_back((nx as i32, ny as i32));
          }
        }
      }
    }

    let (mut l, mut r) = (0, 1_000_000_001);
    while l < r {
      let m = (l + r) / 2;
      if Self::check(m, &grid, &fdist) { l = m + 1; }
      else { r = m; }
    }
    if l == 0 { -1 } else { l - 1 }
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::maximum_minutes(vec![
    vec![0,2,0,0,0,0,0],
    vec![0,0,0,2,2,1,0],
    vec![0,2,0,0,1,2,0],
    vec![0,0,2,2,2,0,2],
    vec![0,0,0,0,0,0,0]
  ]), 3);
  assert_eq!(Solution::maximum_minutes(vec![
    vec![0,0,0,0],
    vec![0,1,2,0],
    vec![0,2,0,0]
  ]), -1);
  assert_eq!(Solution::maximum_minutes(vec![
    vec![0,0,0],
    vec![2,2,0],
    vec![1,2,0]
  ]), 1000000000);
  assert_eq!(Solution::maximum_minutes(vec![
    vec![0,2,0,0,1],
    vec![0,2,0,2,2],
    vec![0,2,0,0,0],
    vec![0,0,2,2,0],
    vec![0,0,0,0,0]
  ]), 0);
  println!("OK");
}
