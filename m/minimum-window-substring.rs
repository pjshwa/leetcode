impl Solution {
  fn c2i(c: char) -> usize {
    if c.is_ascii_lowercase() { c as usize - 'a' as usize }
    else { c as usize - 'A' as usize + 26 }
  }

  pub fn min_window(s: String, t: String) -> String {
    let (mut sc, mut tc) = (vec![0; 52], vec![0; 52]);
    for c in t.chars() { tc[Self::c2i(c)] += 1; }

    let (mut r, mut cnt, n) = (0, 0, s.len());
    for i in 0..52 {
      if tc[i] == 0 { cnt += 1; }
    }

    let s = s.chars().collect::<Vec<char>>();
    let (mut ans, mut lpos) = (0x3f3f3f3f, 0);
    for l in 0..n {
      while r < n && cnt < 52 {
        let i = Self::c2i(s[r]);
        sc[i] += 1;
        if sc[i] == tc[i] { cnt += 1; }
        r += 1;
      }

      if cnt == 52 {
        if r - l < ans {
          ans = r - l;
          lpos = l;
        }
      }

      let i = Self::c2i(s[l]);
      if sc[i] == tc[i] { cnt -= 1; }
      sc[i] -= 1;
    }

    if ans == 0x3f3f3f3f { "".to_string() }
    else { s[lpos..lpos + ans].iter().collect() }
  }
}
