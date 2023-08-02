use std::collections::HashMap;

impl Solution {
  fn dfs(i: usize, m: usize, quantity: &Vec<i32>, v: &mut Vec<i32>) -> bool {
    if i == m { return true; }
    for j in 0..v.len() {
      if v[j] >= quantity[i] {
        v[j] -= quantity[i];
        if Self::dfs(i + 1, m, quantity, v) { return true; }
        v[j] += quantity[i];
      }
    }
    false
  }

  pub fn can_distribute(nums: Vec<i32>, quantity: Vec<i32>) -> bool {
    let mut map = HashMap::new();
    for e in nums.iter() {
      let counter = map.entry(e).or_insert(0);
      *counter += 1;
    }
    let mut v = vec![];
    for (_, &val) in map.iter() { v.push(val); }
    v.sort_by(|a, b| b.cmp(a));

    let mut quantity = quantity;
    quantity.sort_by(|a, b| b.cmp(a));

    // take first m elements of v
    let m = quantity.len();
    while v.len() > m { v.pop(); }
    Self::dfs(0, m, &quantity, &mut v)
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::can_distribute(
    vec![1, 2, 3, 4],
    vec![2]
  ), false);
  assert_eq!(Solution::can_distribute(
    vec![1, 2, 3, 3],
    vec![2]
  ), true);
  assert_eq!(Solution::can_distribute(
    vec![1, 1, 2, 2],
    vec![2, 2]
  ), true);
  println!("OK");
}
