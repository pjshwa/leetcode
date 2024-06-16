use std::collections::BinaryHeap;

impl Solution {
  pub fn get_skyline(buildings: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let mut xs = vec![];
    for b in buildings.iter() { xs.push(b[0]); xs.push(b[1]); }
    xs.sort(); xs.dedup();

    let mut h = BinaryHeap::new();
    let (mut l, n) = (0, buildings.len());

    let mut ans: Vec<Vec<i32>> = vec![];
    for x in xs {
      while l < n && buildings[l][0] <= x {
        h.push((buildings[l][2], buildings[l][1]));
        l += 1;
      }
      while let Some((_, r)) = h.peek() {
        if *r <= x { h.pop(); } else { break; }
      }

      let h = if let Some((h, _)) = h.peek() { *h } else { 0 };
      if ans.is_empty() || ans.last().unwrap()[1] != h {
        ans.push(vec![x, h]);
      }
    }

    ans
  }
}
