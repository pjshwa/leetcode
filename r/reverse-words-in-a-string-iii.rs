impl Solution {
  pub fn reverse_words(s: String) -> String {
    let mut result = String::new();
    for word in s.split_whitespace() {
      word.chars().rev().for_each(|c| result.push(c));
      result.push(' ');
    }
    result.pop();
    result
  }
}
