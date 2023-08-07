fn find(parent: &mut Vec<usize>, x: usize) -> usize {
  if parent[x] == x { return x; }
  parent[x] = find(parent, parent[x]);
  parent[x]
}

fn union(parent: &mut Vec<usize>, usz: &mut Vec<usize>, x: usize, y: usize) {
  let x = find(parent, x);
  let y = find(parent, y);
  if x != y {
    parent[y] = x; 
    usz[x] += usz[y];
  }
}

const MAX: usize = 100001;

impl Solution {
  pub fn largest_component_size(nums: Vec<i32>) -> i32 {
    let (mut parent, mut usz) = (vec![0; MAX], vec![0; MAX]);
    for i in 0..MAX { parent[i] = i; }
    for e in &nums { usz[*e as usize] += 1; }

    let mut ans = 0;
    for e in &nums {
      let e = *e as usize;
      let mut x = e;
      let q = (x as f64).sqrt() as usize;

      for i in 2..=q {
        if x % i == 0 {
          union(&mut parent, &mut usz, e, i);
          while x % i == 0 { x /= i; }
        }
      }
      if x > 1 { union(&mut parent, &mut usz, e, x); }
      ans = ans.max(usz[find(&mut parent, e)]);
    }

    ans as i32
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::largest_component_size(vec![4,6,15,35]), 4);
  assert_eq!(Solution::largest_component_size(vec![20,50,9,63]), 2);
  assert_eq!(Solution::largest_component_size(vec![2,3,6,7,4,12,21,39]), 8);
  println!("OK");
}
