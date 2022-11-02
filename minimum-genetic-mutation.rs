const INF: i32 = 0x3f3f3f3f;

impl Solution {
  fn is_connected(u: &String, v: &String) -> bool {
    let (u, v) = (u.chars().collect::<Vec<char>>(), v.chars().collect::<Vec<char>>());
    let mut diff = 0;
    for i in 0..u.len() {
      if u[i] != v[i] {
        diff += 1;
      }
    }
    diff == 1
  }

  pub fn min_mutation(start: String, end: String, bank: Vec<String>) -> i32 {
    let n = bank.len();
    let mut cost = vec![vec![INF; n + 1]; n + 1];
    cost[0][0] = 0;

    let mut ei = n + 1;
    for i in 0..n {
      cost[i + 1][i + 1] = 0;
      if Self::is_connected(&start, &bank[i]) {
        cost[0][i + 1] = 1;
        cost[i + 1][0] = 1;
      }
      if end == bank[i] {
        ei = i + 1;
      }
    }

    for i in 0..n { for j in 0..n {
      if Self::is_connected(&bank[i], &bank[j]) {
        cost[i + 1][j + 1] = 1;
        cost[j + 1][i + 1] = 1;
      }
    }}

    for k in 0..=n { for i in 0..=n { for j in 0..=n {
      cost[i][j] = cost[i][j].min(cost[i][k] + cost[k][j]);
    }}}

    if ei <= n && cost[0][ei] != INF { cost[0][ei] }
    else { -1 }
  }
}
