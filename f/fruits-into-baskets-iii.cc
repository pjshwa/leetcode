const int INF = 1e9 + 7;

class SegmentTreeMax {

public:
  SegmentTreeMax(int N) {
    n = N;
    for (flag = 1; flag < N; flag <<= 1);
    tmax.resize(2 * flag);
  }

  void update(int P, int val) {
    __update(0, 0, n - 1, P, val);
  }

  int query(int L, int R) {
    return __query(0, n - 1, L, R, 0);
  }

private:
  int n, flag;
  vector<int> tmax;

  void __update(int si, int ss, int se, int p, int val) {
    if (ss > se || ss > p || se < p) return;

    if (ss == se) {
      tmax[si] = val;
      return;
    }

    int mid = (ss + se) / 2;
    __update(si * 2 + 1, ss, mid, p, val);
    __update(si * 2 + 2, mid + 1, se, p, val);

    tmax[si] = max(tmax[si * 2 + 1], tmax[si * 2 + 2]);
  }

  int __query(int ss, int se, int qs, int qe, int si) {
    if (ss > se || ss > qe || se < qs) return -INF;
    if (ss >= qs && se <= qe) return tmax[si];

    int mid = (ss + se) / 2;
    return max(__query(ss, mid, qs, qe, si * 2 + 1), __query(mid + 1, se, qs, qe, si * 2 + 2));
  }
};

class Solution {
public:
  int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int N = fruits.size();

    SegmentTreeMax s(N);
    for (int i = 0; i < N; ++i) s.update(i, baskets[i]);

    int ans = N;
    for (int f : fruits) {
      int l = 0, r = N;
      while (l < r) {
        int m = (l + r) / 2;
        if (s.query(0, m) < f) l = m + 1;
        else r = m;
      }
      if (l < N && s.query(l, l) >= f) {
        s.update(l, -1);
        --ans;
      }
    }

    return ans;
  }
};
