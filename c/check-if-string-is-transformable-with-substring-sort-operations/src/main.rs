impl Solution {
  pub fn is_transformable(s: String, t: String) -> bool {
    let mut by_digit = vec![std::collections::VecDeque::new(); 10];
    for (i, c) in s.chars().enumerate() {
      by_digit[c as usize - '0' as usize].push_back(i);
    }

    for c in t.chars() {
      let d = c as usize - '0' as usize;
      if by_digit[d].is_empty() { return false; }

      for j in 0..d {
        if !by_digit[j].is_empty() && by_digit[j][0] < by_digit[d][0] {
          return false;
        }
      }
      by_digit[d].pop_front();
    }
    true
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::is_transformable("84532".to_string(), "34852".to_string()), true);
  assert_eq!(Solution::is_transformable("34521".to_string(), "23415".to_string()), true);
  assert_eq!(Solution::is_transformable("12345".to_string(), "12435".to_string()), false);
  println!("OK");
}
