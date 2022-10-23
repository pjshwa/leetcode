impl Solution {
  pub fn find_error_nums(nums: Vec<i32>) -> Vec<i32> {
    let mut ans = vec![0; 2];

    let n = nums.len();
    let mut t = vec![0; n + 1];
    for i in 0..n {
      t[nums[i] as usize] += 1;
    }
    for i in 1..=n {
      if t[i] == 2 { ans[0] = i as i32; }
      if t[i] == 0 { ans[1] = i as i32; }
    }
    ans
  }
}
