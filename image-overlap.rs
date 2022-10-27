impl Solution {
  pub fn largest_overlap(img1: Vec<Vec<i32>>, img2: Vec<Vec<i32>>) -> i32 {
    let n = img1.len();
    let mut ans = 0;
    for dx in 0..2 * n { for dy in 0..2 * n {
      let mut cur = 0;
      for i in 0..n { for j in 0..n {
        let (x, y) = (i + dx - n, j + dy - n);
        if 0 <= x && x < n && 0 <= y && y < n && img1[i][j] == 1 && img1[i][j] == img2[x][y] {
          cur += 1;
        }
      }}
      ans = ans.max(cur);
    }}
    ans
  }
}
