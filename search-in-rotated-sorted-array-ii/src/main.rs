impl Solution {
  pub fn search(nums: Vec<i32>, target: i32) -> bool {
    let n = nums.len();

    // first find the pivot index
    let mut b: usize = 0;
    for i in 1..n {
      if nums[i] < nums[i - 1] {
        b = i;
        break;
      }
    }

    // then find the target
    let (mut l, mut r) = (0, n);
    while l < r {
      let m = (l + r) / 2;
      let i = (m + b) % n;

      if nums[i] < target { l = m + 1; }
      else { r = m; }
    }

    nums[(l + b) % n] == target
  }
}

struct Solution;
fn main() {
  // assert_eq!(Solution::search(vec![2,5,6,0,0,1,2], 0), true);
  // assert_eq!(Solution::search(vec![2,5,6,0,0,1,2], 3), false);
  assert_eq!(Solution::search(vec![1,0,1,1,1], 0), true);
  println!("OK");
}
