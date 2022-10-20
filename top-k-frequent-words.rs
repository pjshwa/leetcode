use std::collections::HashMap;

impl Solution {
  pub fn top_k_frequent(words: Vec<String>, k: i32) -> Vec<String> {
    let mut m = HashMap::new();
    for w in words {
      *m.entry(w).or_insert(0) += 1;
    }
    let mut v = m.into_iter().collect::<Vec<_>>();
    v.sort_by(|a, b| {
      if a.1 == b.1 { a.0.cmp(&b.0) }
      else { b.1.cmp(&a.1) }
    });
    v.into_iter().take(k as usize).map(|x| x.0).collect()
  }
}
