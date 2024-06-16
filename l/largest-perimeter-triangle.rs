impl Solution {
  pub fn largest_perimeter(nums: Vec<i32>) -> i32 {
    let mut arr = nums; arr.sort();
    let n = arr.len();

    let mut ans = 0;
    for i in 0..(n - 2) {
      let (a, b, c) = (arr[i], arr[i + 1], arr[i + 2]);
      if a + b > c { ans = a + b + c; }
    }

    ans
  }
}
