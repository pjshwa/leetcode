const int MAXN = 1e5;

class Solution {
  vector<int> pr, lp, D1, D2;

  void init() {
    lp.resize(MAXN + 1);
    D1.resize(MAXN + 1);
    D2.resize(MAXN + 1);
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
  int sumFourDivisors(vector<int>& nums) {
    init();
    for (int p1 : pr) for (int p2 : pr) {
      if (p1 * p2 > MAXN) break;
      if (p1 == p2) continue;
      D1[p1 * p2] = p1;
    }
    for (int p : pr) {
      int p3 = p * p * p;
      if (p3 > MAXN) break;
      D2[p3] = p;
    }

    int ans = 0;
    for (int e : nums) {
      if (D1[e]) ans += (1 + D1[e]) * (1 + e / D1[e]);
      else if (D2[e]) {
        int p = D2[e];
        ans += 1 + p + p * p + e;
      }
    }
    return ans;
  }
};
