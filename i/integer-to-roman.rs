impl Solution {
  pub fn int_to_roman(num: i32) -> String {
    let m = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
    let s = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"];

    let (mut num, mut ans, n) = (num, vec![], m.len());
    for i in 0..n {
      let mut j = num / m[i];
      num %= m[i];
      while j > 0 {
        ans.push(s[i]);
        j -= 1;
      }
    }
    ans.into_iter().collect()
  }
}
