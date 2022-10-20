impl Solution {
  pub fn check_if_pangram(sentence: String) -> bool {
    for t in ('a' as u8)..('z' as u8 + 1) {
      if !sentence.contains(t as char) { return false; }
    }
    true
  }
}
