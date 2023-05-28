class Solution {
  vector<int> A; int N;
  int d[105][105];

  int rec(int l, int r) {
    if (l + 1 == r) return 0;
    if (d[l][r] != -1) return d[l][r];

    int lv = A[l], rv = A[r], ret = 0x3f3f3f3f;
    for (int i = l + 1; i < r; ++i) {
      ret = min(ret, rec(l, i) + rec(i, r) + rv - lv);
    }
    return d[l][r] = ret;
  }

public:
  int minCost(int n, vector<int>& cuts) {
    A.push_back(0); A.push_back(n);
    for (int c : cuts) A.push_back(c);
    sort(A.begin(), A.end()); N = A.size();

    memset(d, -1, sizeof(d));
    return rec(0, N - 1);
  }
};
