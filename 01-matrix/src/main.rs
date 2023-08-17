const DX: [i32; 4] = [0, 0, 1, -1];
const DY: [i32; 4] = [1, -1, 0, 0];

impl Solution {
  pub fn update_matrix(mat: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let (n, m) = (mat.len(), mat[0].len());

    let mut ans = vec![vec![std::i32::MAX; m]; n];
    let mut q = std::collections::VecDeque::new();
    for i in 0..n { for j in 0..m {
      if mat[i][j] == 0 { q.push_back((i, j)); ans[i][j] = 0; }
    }}

    while let Some((x, y)) = q.pop_front() {
      for i in 0..4 {
        let (nx, ny) = (x as i32 + DX[i], y as i32 + DY[i]);
        if nx < 0 || nx >= n as i32 || ny < 0 || ny >= m as i32 { continue; }

        let (nx, ny) = (nx as usize, ny as usize);
        if ans[nx][ny] > ans[x][y] + 1 {
          ans[nx][ny] = ans[x][y] + 1;
          q.push_back((nx, ny));
        }
      }
    }
    ans
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::update_matrix(vec![vec![0,0,0],vec![0,1,0],vec![0,0,0]]), vec![vec![0,0,0],vec![0,1,0],vec![0,0,0]]);
  assert_eq!(Solution::update_matrix(vec![vec![0,0,0],vec![0,1,0],vec![1,1,1]]), vec![vec![0,0,0],vec![0,1,0],vec![1,2,1]]);
  println!("OK");
}
