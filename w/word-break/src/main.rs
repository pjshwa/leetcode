impl Solution {
  pub fn word_break(s: String, word_dict: Vec<String>) -> bool {
    let n = s.len();
    let mut dp = vec![false; n + 1]; dp[0] = true;

    for i in 1..=n {
      for word in &word_dict {
        let len = word.len();
        if len <= i && word == &s[i - len..i] {
          dp[i] = dp[i] || dp[i - len];
        }
      }
    }
    dp[n]
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::word_break("leetcode".to_string(), vec!["leet".to_string(),"code".to_string()]), true);
  assert_eq!(Solution::word_break("applepenapple".to_string(), vec!["apple".to_string(),"pen".to_string()]), true);
  assert_eq!(Solution::word_break("catsandog".to_string(), vec!["cats".to_string(),"dog".to_string(),"sand".to_string(),"and".to_string(),"cat".to_string()]), false);
  println!("OK");
}
