#include <bits/stdc++.h>
using namespace std;

const int MAXK = 6;

struct Node {
  int C[MAXK]{}, val = 1;
  Node() = default;
  Node(int value, int k) : val(value % k) {
    C[val] = 1;
  }
};

class SegmentTree {
  int MOD;

public:
  SegmentTree(int N, int k) {
    n = N; MOD = k;
    for (flag = 1; flag < N; flag <<= 1);
    tree.resize(2 * flag);
  }

  void update(int P, int val) {
    updateImpl(0, 0, n - 1, P, val);
  }

  Node query(int L, int R) {
    return queryImpl(0, n - 1, L, R, 0);
  }

private:
  int n, flag;
  vector<Node> tree;

  void updateImpl(int si, int ss, int se, int p, int val) {
    if (ss > p || se < p) return;

    if (ss == se) {
      tree[si] = Node(val, MOD);
      return;
    }

    int mid = (ss + se) / 2;
    updateImpl(si * 2 + 1, ss, mid, p, val);
    updateImpl(si * 2 + 2, mid + 1, se, p, val);

    tree[si] = merge(tree[si * 2 + 1], tree[si * 2 + 2]);
  }

  Node queryImpl(int ss, int se, int qs, int qe, int si) {
    if (ss > qe || se < qs) return Node();
    if (ss >= qs && se <= qe) return tree[si];

    int mid = (ss + se) / 2;
    return merge(queryImpl(ss, mid, qs, qe, si * 2 + 1),
                 queryImpl(mid + 1, se, qs, qe, si * 2 + 2));
  }

  Node merge(const Node& a, const Node& b) {
    Node res = a;
    res.val = a.val * b.val % MOD;
    for (int i = 0; i < MOD; ++i) {
      res.C[a.val * i % MOD] += b.C[i];
    }
    return res;
  }
};

class Solution {
public:
  vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
    int N = nums.size(); SegmentTree s(N, k);
    for (int i = 0; i < N; ++i) s.update(i, nums[i]);

    vector<int> res;
    for (auto& q : queries) {
      s.update(q[0], q[1]);
      auto pre = s.query(q[2], N - 1);
      res.push_back(pre.C[q[3]]);
    }
    return res;
  }
};
