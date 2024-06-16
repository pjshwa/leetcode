impl Solution {
  pub fn maximal_network_rank(n: i32, roads: Vec<Vec<i32>>) -> i32 {
    let n = n as usize;
    let mut deg = vec![0; n];
    let mut con = vec![vec![false; n]; n];

    for road in roads {
      let (u, v) = (road[0] as usize, road[1] as usize);
      deg[u] += 1; deg[v] += 1;
      con[u][v] = true; con[v][u] = true;
    }

    let mut ans = 0;
    for i in 0..n { for j in i + 1..n {
      let cur = deg[i] + deg[j];
      if con[i][j] { ans = ans.max(cur - 1); }
      else { ans = ans.max(cur); }
    }}
    ans
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::maximal_network_rank(
    4,
    vec![vec![0, 1], vec![0, 3], vec![1, 2], vec![1, 3]]
  ), 4);
  assert_eq!(Solution::maximal_network_rank(
    5,
    vec![vec![0, 1], vec![0, 3], vec![1, 2], vec![1, 3], vec![2, 3], vec![2, 4]]
  ), 5);
  assert_eq!(Solution::maximal_network_rank(
    8,
    vec![vec![0, 1], vec![1, 2], vec![2, 3], vec![2, 4], vec![5, 6], vec![5, 7]]
  ), 5);
  println!("OK");
}
