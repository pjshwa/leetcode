use std::collections::HashSet;

impl Solution {
  pub fn max_length(arr: Vec<String>) -> i32 {
    let n = arr.len();
    let mut ans = 0;
    for state in 0..(1 << n) {
      let mut s = String::new();
      for i in 0..n {
        if state & (1 << i) != 0 {
          s.push_str(&arr[i]);
        }
      }
      if s.len() != s.chars().collect::<HashSet<char>>().len() {
        continue;
      }

      ans = ans.max(s.len() as i32);
    }
    ans
  }
}
