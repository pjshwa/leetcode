impl Solution {
  pub fn find_closest_elements(arr: Vec<i32>, k: i32, x: i32) -> Vec<i32> {
    let n = arr.len();
    if n == 1 { return arr; }

    let mut p = 0;
    for i in 0..n {
      if (arr[i] - x).abs() < (arr[p] - x).abs() { p = i; }
    }

    let mut lr: i32 = -1;
    let mut rr: i32 = -1;
    if p == n - 1 {
      lr = (n - 2) as i32;
      rr = (n - 1) as i32;
    }
    else {
      lr = p as i32;
      rr = (p + 1) as i32;
    }

    let mut ans = vec![];
    while ans.len() < k as usize {
      if lr < 0 {
        ans.push(arr[rr as usize]);
        rr += 1;
      }
      else if rr >= n as i32 {
        ans.push(arr[lr as usize]);
        lr -= 1;
      }
      else {
        if (arr[lr as usize] - x).abs() <= (arr[rr as usize] - x).abs() {
          ans.push(arr[lr as usize]);
          lr -= 1;
        }
        else {
          ans.push(arr[rr as usize]);
          rr += 1;
        }
      }
    }

    ans.sort();
    ans
  }
}
