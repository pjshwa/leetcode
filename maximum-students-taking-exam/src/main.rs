impl Solution {
  fn is_compatible(state_f: usize, state_b: usize, i: usize, m: usize, seats: &Vec<Vec<char>>) -> bool {
    for j in 1..m {
      if (state_b & (1 << j)) != 0 && (state_b & (1 << (j - 1))) != 0 { return false; }
    }
    for j in 0..m {
      if (state_b & (1 << j)) == 0 { continue; }
      if seats[i][j] == '#' { return false; }
      if j > 0 && (state_f & (1 << (j - 1))) != 0 { return false; }
      if j < m - 1 && (state_f & (1 << (j + 1))) != 0 { return false; }
    }
    true
  }

  pub fn max_students(seats: Vec<Vec<char>>) -> i32 {
    let (n, m) = (seats.len(), seats[0].len());
    let mut dp = vec![vec![0 as u32; 1 << m]; n];

    for s in 0..(1 << m) {
      if !Self::is_compatible(0, s, 0, m, &seats) { continue; }
      dp[0][s] = (s as i32).count_ones();
    }
    for i in 1..n {
      for ps in 0..(1 << m) as usize {
        for ns in 0..(1 << m) as usize {
          if !Self::is_compatible(ps, ns, i, m, &seats) { continue; }
          dp[i][ns] = std::cmp::max(dp[i][ns], dp[i - 1][ps] + (ns as i32).count_ones());
        }
      }
    }

    let mut ans = 0 as u32;
    for s in 0..(1 << m) { ans = std::cmp::max(ans, dp[n - 1][s]); }
    ans as i32
  }
}

struct Solution;

#[cfg(test)]
mod tests {
  use super::*;

  #[test]
  fn max_students() {
    assert_eq!(Solution::max_students(vec![vec!['#', '.', '#', '#', '.', '#'], vec!['.', '#', '#', '#', '#', '.'], vec!['#', '.', '#', '#', '.', '#']]), 4);
    assert_eq!(Solution::max_students(vec![vec!['.', '#'], vec!['#', '#'], vec!['#', '.'], vec!['#', '#'], vec!['.', '#']]), 3);
  }
}
