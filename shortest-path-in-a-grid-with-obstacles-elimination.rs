use std::collections::VecDeque;

impl Solution {
  pub fn shortest_path(grid: Vec<Vec<i32>>, k: i32) -> i32 {
    Self::bfs(&grid, k as usize)
  }

  fn bfs(grid: &Vec<Vec<i32>>, k: usize) -> i32 {
    let (n, m) = (grid.len(), grid[0].len());
    let mut dist = vec![vec![vec![i32::MAX; k + 1]; m]; n];

    let mut q = VecDeque::new();
    q.push_back((0, 0, 0));
    dist[0][0][0] = 0;

    while !q.is_empty() {
      let (x, y, z) = q.pop_front().unwrap();
      for (dx, dy) in &[(0, 1), (0, -1), (1, 0), (-1, 0)] {
        let (nx, ny) = (x as i32 + dx, y as i32 + dy);
        if nx < 0 || nx >= n as i32 || ny < 0 || ny >= m as i32 {
          continue;
        }

        let (nx, ny) = (nx as usize, ny as usize);
        if grid[nx][ny] == 1 && z + 1 <= k && dist[nx][ny][z + 1] == i32::MAX {
          dist[nx][ny][z + 1] = dist[x][y][z] + 1;
          q.push_back((nx, ny, z + 1));
        }
        else if grid[nx][ny] == 0 && dist[nx][ny][z] == i32::MAX {
          dist[nx][ny][z] = dist[x][y][z] + 1;
          q.push_back((nx, ny, z));
        }
      }
    }

    let ans = dist[n - 1][m - 1].iter().min().unwrap();
    if ans == &i32::MAX { -1 }
    else { *ans }
  }
}
