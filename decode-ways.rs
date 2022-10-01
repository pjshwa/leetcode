impl Solution {
  pub fn num_decodings(s: String) -> i32 {
    let n = s.len();
    let mut d = vec![0; n + 1];
    let chars: Vec<char> = s.chars().collect();
    d[0] = 1;

    for i in 0..n {
      if chars[i] != '0' {
        d[i + 1] += d[i];
      }
      if i < n - 1 && (chars[i] == '1' || chars[i] == '2' && chars[i + 1] < '7') {
        d[i + 2] += d[i];
      }
    }

    d[n]
  }
}
