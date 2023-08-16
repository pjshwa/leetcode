impl SolutionAlt {
  pub fn count_pyramids(grid: Vec<Vec<i32>>) -> i32 {
    let (n, m) = (grid.len(), grid[0].len());

    let mut pf = vec![vec![0; m + 1]; n + 1];
    for i in 1..=n { for j in 1..=m {
      pf[i][j] = pf[i][j - 1] + grid[i - 1][j - 1] as usize;
    }}

    let mut ans = 0;
    for i in 1..=n { for j in 1..=m {
      if grid[i - 1][j - 1] == 0 { continue; }

      let (mut ni, mut nl, mut nr) = (i + 1, j - 1, j + 1);
      while ni <= n && nl >= 1 && nr <= m {
        if pf[ni][nr] - pf[ni][nl - 1] == nr - nl + 1 {
          ans += 1; ni += 1; nl -= 1; nr += 1;
        }
        else { break; }
      }

      let (mut ni, mut nl, mut nr) = (i - 1, j - 1, j + 1);
      while ni >= 1 && nl >= 1 && nr <= m {
        if pf[ni][nr] - pf[ni][nl - 1] == nr - nl + 1 {
          ans += 1; ni -= 1; nl -= 1; nr += 1;
        }
        else { break; }
      }
    }}
    ans
  }
}

impl Solution {
  pub fn count_pyramids(grid: Vec<Vec<i32>>) -> i32 {
    let (n, m) = (grid.len(), grid[0].len());

    let (mut dp_t, mut dp_b) = (vec![vec![0; m]; n], vec![vec![0; m]; n]);
    for i in (0..n).rev() { for j in 0..m {
      if grid[i][j] == 0 { continue; }

      dp_t[i][j] = 1;
      if i == n - 1 || j == 0 || j == m - 1 { continue; }
      if grid[i + 1][j] == 0 { continue; }

      dp_t[i][j] = dp_t[i + 1][j - 1].min(dp_t[i + 1][j + 1]) + 1;
    }}

    for i in 0..n { for j in 0..m {
      if grid[i][j] == 0 { continue; }

      dp_b[i][j] = 1;
      if i == 0 || j == 0 || j == m - 1 { continue; }
      if grid[i - 1][j] == 0 { continue; }

      dp_b[i][j] = dp_b[i - 1][j - 1].min(dp_b[i - 1][j + 1]) + 1;
    }}

    let mut ans = 0;
    for i in 0..n { for j in 0..m {
      if grid[i][j] == 0 { continue; }

      ans += dp_t[i][j] - 1;
      ans += dp_b[i][j] - 1;
    }}
    ans
  }
}

struct Solution;
struct SolutionAlt;

fn main() {
  assert_eq!(Solution::count_pyramids(vec![vec![0,1,1,0],vec![1,1,1,1]]), 2);
  assert_eq!(Solution::count_pyramids(vec![vec![1,1,1],vec![1,1,1]]), 2);
  assert_eq!(Solution::count_pyramids(vec![vec![1,1,1,1,0],vec![1,1,1,1,1],vec![1,1,1,1,1],vec![0,1,0,0,1]]), 13);
  println!("OK");
}
