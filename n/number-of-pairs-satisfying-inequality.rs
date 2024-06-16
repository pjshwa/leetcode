struct SegmentTree {
  tree: Vec<i64>,
  bias: usize,
}

impl SegmentTree {
  fn new(n: usize) -> Self {
    Self {
      tree: vec![0; (n + 1) * 4],
      bias: {
        let mut bias = 1;
        while bias < (n + 1) { bias *= 2; }
        bias
      },
    }
  }

  fn add(&mut self, idx: usize, val: i64) {
    let mut idx = idx + self.bias;
    self.tree[idx] += val;

    idx /= 2;

    while idx != 0 {
      self.tree[idx] = self.tree[idx * 2] + self.tree[idx * 2 + 1];
      idx /= 2;
    }
  }

  fn query(&mut self, left: usize, right: usize) -> i64 {
    let mut left = left + self.bias;
    let mut right = right + self.bias;
    let mut ret = 0;

    while left < right {
      if (left & 1) != 0 {
        ret += self.tree[left];
        left += 1;
      }
      if (!right & 1) != 0 {
        ret += self.tree[right];
        right -= 1;
      }

      left /= 2;
      right /= 2;
    }

    if left == right { ret += self.tree[left]; }
    ret
  }
}

impl Solution {
  pub fn number_of_pairs(nums1: Vec<i32>, nums2: Vec<i32>, diff: i32) -> i64 {
    let n = nums1.len();
    let mut v = vec![0 as i64; n];
    for i in 0..n { v[i] = (nums1[i] - nums2[i] + 30_000) as i64; }

    let mut s = SegmentTree::new(100_000);
    let diff = diff as i64;
    let mut ans: i64 = 0;
    for i in 0..n {
      ans += s.query(
        0,
        (v[i] + diff) as usize
      );
      s.add(v[i] as usize, 1);
    }
    ans
  }
}
