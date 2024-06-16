impl Solution {
  pub fn minimum_cost(start: Vec<i32>, target: Vec<i32>, special_roads: Vec<Vec<i32>>) -> i32 {
    let (sx, sy, ex, ey) = (start[0], start[1], target[0], target[1]);

    // we will only care about relevant vertices
    let mut vertices = vec![];
    for road in special_roads.iter() {
      let (x1, y1, x2, y2) = (road[0], road[1], road[2], road[3]);
      vertices.push((x1, y1)); vertices.push((x2, y2));
    }
    vertices.push((sx, sy)); vertices.push((ex, ey));

    let n = vertices.len();
    let mut cdist = vec![vec![std::i32::MAX; n]; n];
    for i in 0..n { for j in 0..n {
      let (x1, y1, x2, y2) = (vertices[i].0, vertices[i].1, vertices[j].0, vertices[j].1);
      cdist[i][j] = (x1 - x2).abs() + (y1 - y2).abs();
      cdist[j][i] = cdist[i][j];
    }}

    let z = special_roads.len();
    for i in 0..z {
      let (idx1, idx2, cost) = (2 * i, 2 * i + 1, special_roads[i][4]);
      cdist[idx1][idx2] = cdist[idx1][idx2].min(cost);
    }

    // n is small enough to run floyd-warshall
    for k in 0..n { for i in 0..n { for j in 0..n {
      cdist[i][j] = cdist[i][j].min(cdist[i][k] + cdist[k][j]);
    }}}
    cdist[n - 2][n - 1]
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::minimum_cost(
    vec![1,1],
    vec![4,5],
    vec![vec![1,2,3,3,2], vec![3,4,4,5,1]]
  ), 5);
  assert_eq!(Solution::minimum_cost(
    vec![3,2],
    vec![5,7],
    vec![vec![3,2,3,4,4], vec![3,3,5,5,5], vec![3,4,5,6,6]]
  ), 7);
  println!("OK");
}
