impl Solution {
  fn l2v(l: i32) -> i32 {
    if l >= 100 { 4 }
    else if l >= 10 { 3 }
    else if l > 1 { 2 }
    else { 1 }
  }

  fn dfs(
    s: &Vec<char>,
    d: &mut Vec<Vec<i32>>,
    left: usize,
    k: usize,
  ) -> i32 {
    let (n, mut k, ok) = (s.len(), k, k);
    if n - left <= k { return 0; }
    if d[left][k] != -1 { return d[left][k]; }

    let mut res = if k > 0 { Self::dfs(s, d, left + 1, k - 1) } else { 0x3f3f3f3f };
    let mut cnt = 1;
    for i in left + 1..=n {
      res = res.min(Self::l2v(cnt) + Self::dfs(s, d, i, k));
      if i == n { break; }
      if s[i] == s[left] { cnt += 1; }
      else if k > 0 { k -= 1; }
      else { break; }
    }

    d[left][ok] = res;
    res
  }

  pub fn get_length_of_optimal_compression(s: String, k: i32) -> i32 {
    let (n, k) = (s.len(), k as usize);
    let mut d = vec![vec![-1; n + 1]; n + 1];
    let s = s.chars().collect::<Vec<_>>();

    Self::dfs(&s, &mut d, 0, k)
  }
}
