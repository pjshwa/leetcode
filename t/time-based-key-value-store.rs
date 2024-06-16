use std::collections::HashMap;

struct TimeMap {
  vmap: HashMap<String, Vec<(i32, String)>>,
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl TimeMap {
  fn new() -> Self {
    Self {
      vmap: HashMap::new(),
    }
  }

  fn set(&mut self, key: String, value: String, timestamp: i32) {
    let vmap = &mut self.vmap;
    vmap.entry(key).or_insert(vec![]).push((timestamp, value));
  }

  fn get(&self, key: String, timestamp: i32) -> String {
    let vmap = &self.vmap;
    if let Some(v) = vmap.get(&key) {
      v.binary_search_by_key(&timestamp, |&(t, _)| t)
        .map(|i| v[i].1.clone())
        .unwrap_or_else(|i| {
          if i > 0 { v[i - 1].1.clone() } else { "".to_string() }
        })
    }
    else {
      "".to_string()
    }
  }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * let obj = TimeMap::new();
 * obj.set(key, value, timestamp);
 * let ret_2: String = obj.get(key, timestamp);
 */
