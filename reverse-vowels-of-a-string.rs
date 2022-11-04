impl Solution {
  pub fn reverse_vowels(s: String) -> String {
    let mut s: Vec<char> = s.chars().collect();
    let n = s.len(); let mut sta = vec![];
    for i in 0..n {
      if "aeiouAEIOU".contains(s[i]) { sta.push(s[i]); }
    }
    for i in 0..n {
      if "aeiouAEIOU".contains(s[i]) { s[i] = sta.pop().unwrap(); }
    }
    s.into_iter().collect()
  }
}
