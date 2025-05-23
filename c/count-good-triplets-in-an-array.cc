class SegmentTree {
public:
  SegmentTree(int N) {
    n = N;
    for (flag = 1; flag < N; flag <<= 1);
    tree.resize(2 * flag);
  }

  void add(int P, int val) {
    __add(0, 0, n - 1, P, val);
  }

  int query(int L, int R) {
    return __query(0, n - 1, L, R, 0);
  }

private:
  int n, flag;
  vector<int> tree;

  void __add(int si, int ss, int se, int p, int val) {
    if (ss > se || ss > p || se < p) return;

    if (ss == se) {
      tree[si] += val;
      return;
    }

    int mid = (ss + se) / 2;
    __add(si * 2 + 1, ss, mid, p, val);
    __add(si * 2 + 2, mid + 1, se, p, val);

    tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
  }

  int __query(int ss, int se, int qs, int qe, int si) {
    if (ss > se || ss > qe || se < qs) return 0;
    if (ss >= qs && se <= qe) return tree[si];

    int mid = (ss + se) / 2;
    return __query(ss, mid, qs, qe, si * 2 + 1) + __query(mid + 1, se, qs, qe, si * 2 + 2);
  }
};

class Solution {
public:
  long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
    int N = nums1.size(); vector<int> V(N), P(N);
    for (int i = 0; i < N; ++i) V[nums1[i]] = i;
    for (int i = 0; i < N; ++i) {
      nums2[i] = V[nums2[i]];
      P[nums2[i]] = i;
    }

    SegmentTree L(N), R(N);
    for (int i = 0; i < N; ++i) R.add(P[i], 1);
    long long ans = 0;
    for (int i = 0; i < N; ++i) {
      R.add(P[i], -1);
      ans += (long long)L.query(0, P[i] - 1) * R.query(P[i] + 1, N - 1);
      L.add(P[i], 1);
    }
    return ans;
  }
};
