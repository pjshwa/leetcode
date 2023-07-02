using ll = long long;

class Solution {

  bool is_prime(ll n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (ll i = 3; i * i <= n; i += 2) {
      if (n % i == 0) return false;
    }
    return true;
  }

public:
  vector<vector<int>> findPrimePairs(int n) {
    vector<vector<int>> ans;
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
