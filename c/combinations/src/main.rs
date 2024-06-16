impl Solution {
  fn dfs(s: usize, i: usize, n: usize, k: usize, cur: &mut Vec<i32>, ans: &mut Vec<Vec<i32>>) {
    if i == k {
      ans.push(cur.clone());
      return;
    }

    for j in s..=n {
      cur.push(j as i32);
      Self::dfs(j + 1, i + 1, n, k, cur, ans);
      cur.pop();
    }
  }

  pub fn combine(n: i32, k: i32) -> Vec<Vec<i32>> {
    let mut ans: Vec<Vec<i32>> = Vec::new();
    let mut cur: Vec<i32> = Vec::new();

    let (n, k) = (n as usize, k as usize);
    for j in 1..=n {
      cur.push(j as i32);
      Self::dfs(j + 1, 1, n, k, &mut cur, &mut ans);
      cur.pop();
    }
    ans
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::combine(4, 2), vec![vec![1,2],vec![1,3],vec![1,4],vec![2,3],vec![2,4],vec![3,4]]);
  assert_eq!(Solution::combine(1, 1), vec![vec![1]]);
  println!("OK");
}
