struct UnionFind {
  par: Vec<usize>,
  usz: Vec<usize>,
  n: usize,
}

impl UnionFind {
  fn new(n: usize) -> Self {
    Self {
      par: (0..n).collect(),
      usz: vec![1; n],
      n
    }
  }

  fn find(&mut self, x: usize) -> usize {
    if self.par[x] == x { x }
    else {
      let p = self.par[x];
      self.par[x] = self.find(p);
      self.par[x]
    }
  }

  fn unite(&mut self, x: usize, y: usize) {
    let x = self.find(x);
    let y = self.find(y);
    if x == y { return; }
    self.par[x] = y;
    self.usz[y] += self.usz[x];
  }

  fn reset(&mut self) {
    self.par = (0..self.n).collect();
    self.usz = vec![1; self.n];
  }
}

impl Solution {
  pub fn equations_possible(equations: Vec<String>) -> bool {
    let mut uf = UnionFind::new(26);

    for eq in equations.iter() {
      let eq = eq.as_bytes();
      if eq[1] == b'=' {
        let x = (eq[0] - b'a') as usize;
        let y = (eq[3] - b'a') as usize;
        uf.unite(x, y);
      }
    }
    for eq in equations.iter() {
      let eq = eq.as_bytes();
      if eq[1] == b'!' {
        let x = (eq[0] - b'a') as usize;
        let y = (eq[3] - b'a') as usize;
        if uf.find(x) == uf.find(y) {
          return false;
        }
      }
    }

    true
  }
}
