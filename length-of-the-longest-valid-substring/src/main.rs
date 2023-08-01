use std::collections::HashSet;

impl Solution {
  pub fn longest_valid_substring(word: String, forbidden: Vec<String>) -> i32 {
    let n = word.len();
    let f_set = forbidden.into_iter().collect::<HashSet<String>>();

    let (mut l, mut ans) = (0, 0);
    for r in 0..n {
      for j in 1..=10 {
        if r < j - 1 { break; }

        // check if f_set contains rightmost j chars of string
        if f_set.contains(&word[r + 1 - j..r + 1]) {
          l = l.max(r + 2 - j);
        }
      }
      ans = ans.max(r + 1 - l);
    }
    ans as i32
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::longest_valid_substring(
    "cbaaaabc".to_string(),
    vec!["aaa".to_string(), "cb".to_string()]
  ), 4);
  assert_eq!(Solution::longest_valid_substring(
    "leetcode".to_string(),
    vec!["de".to_string(), "le".to_string(), "e".to_string()]
  ), 4);
  println!("OK");
}
