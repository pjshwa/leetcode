use std::collections::BinaryHeap;

impl Solution {
  pub fn min_cost(colors: String, needed_time: Vec<i32>) -> i32 {
    let n = colors.len();
    let chars = colors.chars().collect::<Vec<char>>();

    let mut last = ' ';
    let mut h = BinaryHeap::new();
    let mut ans = 0;

    for i in 0..n {
      if chars[i] != last {
        if let Some(v) = h.peek() { ans -= v; }
        while let Some(v) = h.peek() { ans += v; h.pop(); }
        last = chars[i];
      }
      h.push(needed_time[i]);
    }

    if let Some(v) = h.peek() { ans -= v; }
    while let Some(v) = h.peek() { ans += v; h.pop(); }

    ans
  }
}
