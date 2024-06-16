use std::collections::HashMap;

impl Solution {
  fn dfs(i: usize, n: usize, ans: &mut Vec<String>, digits: &Vec<char>, by_digit: &HashMap<char, Vec<char>>, cur: &mut Vec<char>) {
    if i == n {
      ans.push(cur.iter().collect());
      return;
    }

    let digit = digits[i];
    let letters = by_digit.get(&digit).unwrap();
    for letter in letters {
      cur.push(*letter);
      Self::dfs(i + 1, n, ans, digits, by_digit, cur);
      cur.pop();
    }
  }

  pub fn letter_combinations(digits: String) -> Vec<String> {
    let mut by_digit = HashMap::new();
    by_digit.insert('2', vec!['a', 'b', 'c']);
    by_digit.insert('3', vec!['d', 'e', 'f']);
    by_digit.insert('4', vec!['g', 'h', 'i']);
    by_digit.insert('5', vec!['j', 'k', 'l']);
    by_digit.insert('6', vec!['m', 'n', 'o']);
    by_digit.insert('7', vec!['p', 'q', 'r', 's']);
    by_digit.insert('8', vec!['t', 'u', 'v']);
    by_digit.insert('9', vec!['w', 'x', 'y', 'z']);

    let digits: Vec<char> = digits.chars().collect();
    let n = digits.len();
    if n == 0 { return vec![]; }

    let (mut ans, mut cur) = (vec![], vec![]);
    Self::dfs(0, n, &mut ans, &digits, &by_digit, &mut cur);

    ans
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::letter_combinations("23".to_string()), vec!["ad","ae","af","bd","be","bf","cd","ce","cf"]);
  assert_eq!(Solution::letter_combinations("".to_string()), Vec::<String>::new());
  assert_eq!(Solution::letter_combinations("2".to_string()), vec!["a","b","c"]);
  println!("OK");
}
