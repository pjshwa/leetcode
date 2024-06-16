impl Solution {
  pub fn push_dominoes(dominoes: String) -> String {
    let n = dominoes.len();
    let chars: Vec<char> = dominoes.chars().collect();
    let mut ans = vec!['.'; n];

    let mut li = 0;
    let mut lc = ' ';
    for i in 0..n {
      let c = chars[i];
      if c == 'L' {
        if lc == 'R' {
          let w = (i - li + 1) / 2;
          for i in li..li + w { ans[i] = 'R'; }
          for i in i - w + 1..=i { ans[i] = 'L'; }
        }
        else {
          for i in li..=i { ans[i] = 'L'; }
        }
        li = i;
        lc = c;
      }
      if c == 'R' {
        if lc == 'R' {
          for i in li..=i { ans[i] = 'R'; }
        }
        li = i;
        lc = c;
      }
    }
    if lc == 'R' {
      for i in li..n { ans[i] = 'R'; }
    }

    return ans.into_iter().collect();
  }
}
