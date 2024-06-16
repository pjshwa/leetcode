use std::collections::HashMap;

impl Solution {
  pub fn longest_palindrome(words: Vec<String>) -> i32 {
    let mut freq: HashMap<String, i32> = words
            .into_iter()
            .fold(HashMap::new(), |mut f, w| { *f.entry(w).or_default() += 1; f });

    let (mut o, mut ans) = (false, 0);
    for (word, count) in freq.iter() {
      if word.bytes().rev().eq(word.bytes()) {
        ans += count / 2 * 2;
        if count % 2 == 1 {
          o = true;
        }
      }
      else {
        let rstr = word.chars().rev().collect::<String>();
        ans += count.min(freq.get(&rstr).unwrap_or(&0));
      }
    }

    if o { ans += 1; }
    ans * 2
  }
}
