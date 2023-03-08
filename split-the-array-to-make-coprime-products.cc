using ll = long long;
const int MAX = 1e6;

class Solution {
  int lp[MAX + 1], L[MAX + 1], R[MAX + 1];
  vector<int> pr;

  void init() {
    memset(lp, 0, sizeof(lp));
    memset(L, 0, sizeof(L));
    memset(R, 0, sizeof(R));

    // Sieve of Eratosthenes O(n)
    for (ll i = 2; i <= MAX; ++i) {
      if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back(i);
      }
      for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= MAX; j++)
        lp[i * pr[j]] = pr[j];
    }
  }

public:
  int findValidSplit(vector<int>& nums) {
    init();
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int x = nums[i];
      while (x > 1) {
        R[lp[x]]++;
        x /= lp[x];
      }
    }

    int lcnt = 0, rcnt = 0;
    for (int i = 0; i < n - 1; i++) {
      int x = nums[i];
      while (x > 1) {
        int p = lp[x];

        R[p]--;
        if (R[p] == 0) rcnt++;

        if (L[p] == 0) lcnt++;
        L[p]++;
        x /= p;
      }

      if (lcnt == rcnt) return i;
    }
    return -1;
  }
};
