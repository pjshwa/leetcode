/** 
 * The rand7() API is already defined for you.
 * @return a random integer in the range 1 to 7
 * fn rand7() -> i32;
 */

fn rand7() -> i32 {
  1
}

impl Solution {
  fn rand49() -> i32 {
    7 * (rand7() - 1) + rand7()
  }

  pub fn rand10() -> i32 {
    loop {
      let n = Self::rand49();
      if n <= 40 {
        return n % 10 + 1;
      }
    }
    -1
  }
}

struct Solution;
fn main() {
  Solution::rand10();
  println!("OK");
}
