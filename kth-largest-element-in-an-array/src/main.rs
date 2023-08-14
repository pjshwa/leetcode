impl Solution {
  fn quick_select(nums: &Vec<i32>, k: usize) -> i32 {
    let (mut l, mut r) = (vec![], vec![]);
    let (pivot, n) = (nums[0], nums.len());

    for i in 1..n {
      if nums[i] > pivot { l.push(nums[i]); }
      if nums[i] < pivot { r.push(nums[i]); }
    }

    if l.len() >= k {
      Self::quick_select(&l, k)
    }
    else if n - r.len() < k {
      Self::quick_select(&r, k - (n - r.len()))
    }
    else { pivot }
  }

  pub fn find_kth_largest(nums: Vec<i32>, k: i32) -> i32 {
    Self::quick_select(&nums, k as usize)
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::find_kth_largest(vec![3, 2, 1, 5, 6, 4], 2), 5);
  assert_eq!(Solution::find_kth_largest(vec![3, 2, 3, 1, 2, 4, 5, 5, 6], 4), 4);
  println!("OK");
}
