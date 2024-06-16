use std::collections::BinaryHeap;
use std::cmp::Reverse;
const INF: i64 = 1 << 50;

impl Solution {
  pub fn minimum_weight(n: i32, edges: Vec<Vec<i32>>, src1: i32, src2: i32, dest: i32) -> i64 {

    let n = n as usize;
    let mut adj = vec![vec![]; n];
    let mut radj = vec![vec![]; n];

    for ev in edges {
      let (u, v, w) = (ev[0] as usize, ev[1] as usize, ev[2] as i64);
      adj[u].push((v, w)); radj[v].push((u, w));
    }

    let (s1, s2, dest) = (src1 as usize, src2 as usize, dest as usize);
    let (mut cdist1, mut cdist2, mut rdist) = (vec![INF; n], vec![INF; n], vec![INF; n]);
    {
      let mut pq: BinaryHeap<(Reverse<i64>, usize)> = BinaryHeap::new();
      pq.push((Reverse(0), s1)); cdist1[s1] = 0;

      while let Some((Reverse(d), u)) = pq.pop() {
        if d > cdist1[u] { continue; }
        for &(v, w) in adj[u].iter() {
          if cdist1[v] > cdist1[u] + w {
            cdist1[v] = cdist1[u] + w;
            pq.push((Reverse(cdist1[v]), v));
          }
        }
      }
    }
    {
      let mut pq: BinaryHeap<(Reverse<i64>, usize)> = BinaryHeap::new();
      pq.push((Reverse(0), s2)); cdist2[s2] = 0;

      while let Some((Reverse(d), u)) = pq.pop() {
        if d > cdist2[u] { continue; }
        for &(v, w) in adj[u].iter() {
          if cdist2[v] > cdist2[u] + w {
            cdist2[v] = cdist2[u] + w;
            pq.push((Reverse(cdist2[v]), v));
          }
        }
      }
    }
    {
      let mut pq: BinaryHeap<(Reverse<i64>, usize)> = BinaryHeap::new();
      pq.push((Reverse(0), dest)); rdist[dest] = 0;

      while let Some((Reverse(d), u)) = pq.pop() {
        if d > rdist[u] { continue; }
        for &(v, w) in radj[u].iter() {
          if rdist[v] > rdist[u] + w {
            rdist[v] = rdist[u] + w;
            pq.push((Reverse(rdist[v]), v));
          }
        }
      }
    }

    let mut ans = cdist1[dest] + cdist2[dest];
    for m in 0..n {
      ans = ans.min(cdist1[m] + cdist2[m] + rdist[m]);
    }
    if ans >= INF { -1 } else { ans }
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::minimum_weight(
    6,
    vec![vec![0,2,2],vec![0,5,6],vec![1,0,3],vec![1,4,5],vec![2,1,1],vec![2,3,3],vec![2,3,4],vec![3,4,2],vec![4,5,1]],
    0, 1, 5
  ), 9);
  assert_eq!(Solution::minimum_weight(
    3,
    vec![vec![0,1,1],vec![2,1,1]],
    0, 1, 2
  ), -1);
  println!("OK");
}
