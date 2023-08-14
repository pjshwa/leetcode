const INF: usize = 1e18 as usize;
const LIM: usize = 1e9 as usize;

impl Solution {
  pub fn minimum_finish_time(tires: Vec<Vec<i32>>, change_time: i32, num_laps: i32) -> i32 {
    let (change_time, num_laps) = (change_time as usize, num_laps as usize);

    let mut ftime = vec![INF; num_laps + 1]; ftime[0] = 0;
    for tire in tires {
      let (mut f, t) = (tire[0] as usize, tire[1] as usize);
      let mut tot = f;

      ftime[1] = ftime[1].min(tot);
      for i in 2..=num_laps {
        f *= t; tot += f;
        if tot > LIM { break; }
        ftime[i] = ftime[i].min(tot);
      }
    }

    let mut dp = vec![INF; num_laps + 1]; dp[0] = 0;
    for i in 1..=num_laps {
      for j in (0..=i).rev() {
        let dif = i - j;
        if ftime[dif] == INF { break; }

        let val = dp[j] + ftime[dif] + if j == 0 { 0 } else { change_time };
        dp[i] = dp[i].min(val);
      }
    }
    dp[num_laps] as i32
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::minimum_finish_time(vec![vec![2, 3], vec![3, 4]], 5, 4), 21);
  assert_eq!(Solution::minimum_finish_time(vec![vec![1, 10], vec![2, 2], vec![3, 4]], 6, 5), 25);
  assert_eq!(Solution::minimum_finish_time(vec![vec![99, 7]], 85, 95), 17395);
  println!("OK");
}
