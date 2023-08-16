use std::collections::BinaryHeap;

impl SolutionAlt {
  pub fn max_sliding_window(nums: Vec<i32>, k: i32) -> Vec<i32> {
    let (n, k) = (nums.len(), k as usize);

    let (mut max_heap, mut ans) = (BinaryHeap::new(), Vec::new());
    for i in 0..k { max_heap.push((nums[i], i)); }
    ans.push(max_heap.peek().unwrap().0);

    for i in k..n {
      while let Some(&(_, j)) = max_heap.peek() {
        if j <= i - k { max_heap.pop(); }
        else { break; }
      }
      max_heap.push((nums[i], i));
      ans.push(max_heap.peek().unwrap().0);
    }
    ans
  }
}

use std::collections::VecDeque;

impl Solution {
  pub fn max_sliding_window(nums: Vec<i32>, k: i32) -> Vec<i32> {
    let (n, k) = (nums.len(), k as usize);

    let (mut d, mut ans) = (VecDeque::new(), Vec::new());
    for i in 0..k {
      let tuple = (nums[i], i);
      while !d.is_empty() && d.back().unwrap() < &tuple { d.pop_back(); }
      d.push_back(tuple);
    }
    ans.push(d.front().unwrap().0);

    for i in k..n {
      let tuple = (nums[i], i);
      while !d.is_empty() && d.front().unwrap().1 <= i - k { d.pop_front(); }
      while !d.is_empty() && d.back().unwrap() < &tuple { d.pop_back(); }
      d.push_back(tuple);

      ans.push(d.front().unwrap().0);
    }
    ans
  }
}

struct Solution;
struct SolutionAlt;

fn main() {
  assert_eq!(Solution::max_sliding_window(vec![1,3,-1,-3,5,3,6,7], 3), vec![3,3,5,5,6,7]);
  assert_eq!(Solution::max_sliding_window(vec![1], 1), vec![1]);
  println!("OK");
}
