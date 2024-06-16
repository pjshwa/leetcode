use std::collections::BTreeMap;

fn find(parent: &mut Vec<usize>, x: usize) -> usize {
  if parent[x] == x { return x; }
  parent[x] = find(parent, parent[x]);
  parent[x]
}

fn union(parent: &mut Vec<usize>, usz: &mut Vec<usize>, x: usize, y: usize) {
  let x = find(parent, x);
  let y = find(parent, y);
  if x != y {
    parent[y] = x; 
    usz[x] += usz[y];
  }
}

impl Solution {
  pub fn valid_subarray_size(nums: Vec<i32>, threshold: i32) -> i32 {
    let n = nums.len();
    let mut t_vec = vec![];

    // value => [indices]
    let mut v_map = BTreeMap::new();
    for i in 0..n {
      let e = nums[i];
      let val = (threshold / e) + 1;
      t_vec.push(val);
      v_map.entry(val).or_insert(vec![]).push(i);
    }

    let mut parent = vec![0; n]; let mut usz = vec![1; n];
    for i in 0..n { parent[i] = i; }

    let mut maxz = 1;
    for (val, indices) in v_map.iter() {
      for &i in indices {
        if i > 0 && t_vec[i - 1] <= *val {
          union(&mut parent, &mut usz, i - 1, i);
          maxz = maxz.max(usz[find(&mut parent, i)]);
        }
        if i + 1 < n && t_vec[i + 1] <= *val {
          union(&mut parent, &mut usz, i + 1, i);
          maxz = maxz.max(usz[find(&mut parent, i)]);
        }
      }

      if *val <= (maxz as i32) { return *val }
    }

    -1
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::valid_subarray_size(vec![1, 3, 4, 3, 1], 6), 3);
  assert_eq!(Solution::valid_subarray_size(vec![6, 5, 6, 5, 8], 7), 1);
  println!("OK");
}
