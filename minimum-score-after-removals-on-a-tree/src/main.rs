use std::collections::VecDeque;

fn f(u1: usize, u2: usize, u3: usize) -> usize {
  let mut v = vec![u1, u2, u3]; v.sort();
  v[2] - v[0]
}

fn dfs1(v: usize, p: usize, adj: &Vec<Vec<usize>>, dp: &mut Vec<usize>, nums: &Vec<i32>) {
  dp[v] = nums[v] as usize;
  for &u in &adj[v] {
    if u == p { continue; }
    dfs1(u, v, adj, dp, nums);
    dp[v] ^= dp[u];
  }
}

fn dfs2(
  v: usize,
  p: usize,
  vp1: usize,
  vp2: usize,
  ans: &mut usize,
  adj: &Vec<Vec<usize>>,
  dp: &mut Vec<usize>,
  nums: &Vec<i32>
) {
  for &u in &adj[v] {
    if u == p { continue; }
    *ans = (*ans).min(f(dp[u], vp1 ^ dp[u], vp2));
    dfs2(u, v, vp1, vp2, ans, adj, dp, nums);
  }
}

impl Solution {
  pub fn minimum_score(nums: Vec<i32>, edges: Vec<Vec<i32>>) -> i32 {
    let n = nums.len();
    let mut ans: usize = 1 << 30;

    for u in 0..n - 1 {
      let mut adj = vec![vec![]; n];
      for i in 0..n - 1 {
        if i == u { continue; }

        let (u, v) = (edges[i][0] as usize, edges[i][1] as usize);
        adj[u].push(v); adj[v].push(u);
      }

      let (mut v1, mut v2) = (n, n);
      let mut vis = vec![false; n];
      let mut q = VecDeque::new();

      for i in 0..n {
        if vis[i] { continue; }

        if v1 == n { v1 = i; }
        else { v2 = i; break; }

        q.push_back(i);
        while let Some(u) = q.pop_front() {
          vis[u] = true;
          for &v in &adj[u] { if !vis[v] { q.push_back(v); vis[v] = true; } }
        }
      }

      let mut dp = vec![0; n];
      dfs1(v1, n, &adj, &mut dp, &nums);
      dfs1(v2, n, &adj, &mut dp, &nums);

      dfs2(v1, n, dp[v1], dp[v2], &mut ans, &adj, &mut dp, &nums);
      dfs2(v2, n, dp[v2], dp[v1], &mut ans, &adj, &mut dp, &nums);
    }

    ans as i32
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::minimum_score(vec![1,5,5,4,11], vec![vec![0,1],vec![1,2],vec![1,3],vec![1,4]]), 9);
  assert_eq!(Solution::minimum_score(vec![5,5,2,4,4,2], vec![vec![0,1],vec![1,2],vec![5,2],vec![4,3],vec![1,3]]), 0);
  assert_eq!(Solution::minimum_score(vec![9,14,2,1], vec![vec![2,3],vec![3,0],vec![3,1]]), 11);
  println!("OK");
}
