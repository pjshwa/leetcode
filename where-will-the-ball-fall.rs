impl Solution {
  pub fn find_ball(grid: Vec<Vec<i32>>) -> Vec<i32> {
    let (n, m) = (grid.len(), grid[0].len());
    let mut ans = vec![-1; m];

    for j in 0..m {
      let (mut c, mut f) = (j, true);
      for i in 0..n {
        if grid[i][c] == 1 {
          if c + 1 < m && grid[i][c + 1] == 1 {
            c += 1;
          }
          else {
            f = false;
            break;
          }
        }
        else {
          if c > 0 && grid[i][c - 1] == -1 {
            c -= 1;
          }
          else {
            f = false;
            break;
          }
        }
      }

      if f { ans[j] = c as i32; }
    }

    ans
  }
}
