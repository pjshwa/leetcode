use std::collections::HashMap;

impl Solution {
  pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
    let mut s = HashMap::new();
    for str in strs {
      let mut key = [0; 26];
      for c in str.chars() {
        key[c as usize - 'a' as usize] += 1;
      }
      s.entry(key).or_insert(Vec::new()).push(str);
    }
    s.values().map(|v| v.clone()).collect()
  }
}
