using ll = long long;
const int MAX = 1e6;
int lp[MAX + 1];
vector<int> pr;

class Solution {
  void init() {
    if (lp[2] == 2) return;

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

  bool is_prime(int n) {
    if (n < 2) return false;
    return lp[n] == n;
  }

public:
  vector<vector<int>> findPrimePairs(int n) {
    vector<vector<int>> ans;

    init();
    for (int i = 2; i <= n; i++) {
      int j = n - i;
      if (i > j) break;
      if (is_prime(i) && is_prime(j)) {
        ans.push_back({i, j});
      }
    }
    return ans;
  }
};
