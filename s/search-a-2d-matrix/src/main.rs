impl Solution {
  pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
    let n = matrix.len();

    let (mut l, mut r) = (0, n);
    while l < r {
      let m = (l + r) / 2;

      if matrix[m][0] > target { r = m; }
      else { l = m + 1; }
    }

    l > 0 && matrix[l - 1].binary_search(&target).is_ok()
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::search_matrix(vec![vec![1,3,5,7],vec![10,11,16,20],vec![23,30,34,60]], 3), true);
  assert_eq!(Solution::search_matrix(vec![vec![1,3,5,7],vec![10,11,16,20],vec![23,30,34,60]], 13), false);
  println!("OK");
}
