impl Solution {
  pub fn search(nums: Vec<i32>, target: i32) -> i32 {
    let n = nums.len();
    let b: usize;
    {
      let (mut l, mut r) = (0, n);
      while l < r {
        let m = (l + r) / 2;

        if nums[m] < nums[0] { r = m; }
        else { l = m + 1; }
      }
      b = l;
    }

    let (mut l, mut r) = (0, n);
    while l < r {
      let m = (l + r) / 2;

      if nums[(b + m) % n] < target { l = m + 1; }
      else { r = m; }
    }

    if nums[(b + l) % n] == target { ((b + l) % n) as i32 }
    else { -1 }
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::search(vec![4,5,6,7,0,1,2], 0), 4);
  assert_eq!(Solution::search(vec![4,5,6,7,0,1,2], 3), -1);
  assert_eq!(Solution::search(vec![1], 0), -1);
  println!("OK");
}
