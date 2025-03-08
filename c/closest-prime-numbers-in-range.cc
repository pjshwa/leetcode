const int MAXN = 1e6;

class Solution {
  vector<int> pr, lp;

  void init() {
    lp.resize(MAXN + 1);
    for (long long i = 2; i <= MAXN; ++i) {
      if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back(i);
      }
      for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= MAXN; j++)
        lp[i * pr[j]] = pr[j];
    }
  }

public:
  vector<int> closestPrimes(int left, int right) {
    init();
    int l = -1, r = -1, diff = MAXN + 10;
    for (int i = 1; i < pr.size(); ++i) {
      int p1 = pr[i - 1], p2 = pr[i];
      if (left <= p1 && p2 <= right && p2 - p1 < diff) {
        l = p1, r = p2, diff = p2 - p1;
      }
    }
    return {l, r};
  }
};
