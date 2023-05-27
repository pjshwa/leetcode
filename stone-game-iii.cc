const int MAX = 5e4, INF = 0x3f3f3f3f;

class Solution {
  vector<int> A; int N;
  int d[MAX][2];

  int r(int i, int p) {
    if (i >= N) return 0;
    if (d[i][p] != -INF) return d[i][p];

    int ret = p ? INF : -INF, acc = 0;
    for (int a = 1; a <= 3; a++) {
      if (i + a > N) break;
      acc += A[i + a - 1];

      if (p) ret = min(ret, r(i + a, 1 - p) - acc);
      else ret = max(ret, r(i + a, 1 - p) + acc);
    }
    return d[i][p] = ret;
  }

public:
  string stoneGameIII(vector<int>& stoneValue) {
    this->A = stoneValue; this->N = A.size();
    for (int i = 0; i < N; i++) d[i][0] = d[i][1] = -INF;

    int ret = r(0, 0);
    if (ret > 0) return "Alice";
    if (ret < 0) return "Bob";
    return "Tie";
  }
};
