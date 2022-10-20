impl Solution {
  pub fn count_and_say(n: i32) -> String {
    if n == 1 { return "1".to_string(); }

    let prv = Self::count_and_say(n - 1);
    let mut ret = String::new();

    let (mut lchar, mut streak) = (' ', 0);
    for c in prv.chars() {
      if c == lchar { streak += 1; }
      else {
        if streak > 0 { ret.push_str(&format!("{}{}", streak, lchar)); }
        streak = 1;
        lchar = c;
      }
    }
    if streak > 0 { ret.push_str(&format!("{}{}", streak, lchar)); }

    ret
  }
}
