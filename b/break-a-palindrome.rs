impl Solution {
  pub fn break_palindrome(palindrome: String) -> String {
    let n = palindrome.len();
    if n == 1 { return "".to_string(); }

    let mut all_a = true;
    let mut chars: Vec<char> = palindrome.chars().collect();
    for i in 0..(n / 2) {
      all_a = all_a && chars[i] == 'a' && chars[n - i - 1] == 'a';
    }

    if all_a { chars[n - 1] = 'b'; }
    else {
      for i in 0..n {
        if chars[i] != 'a' {
          chars[i] = 'a';
          break;
        }
      }
    }

    chars.iter().collect()
  }
}
