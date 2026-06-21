const int MAXN = 1e5;

class Solution {
public:
  int maxIceCream(vector<int>& costs, int coins) {
    vector<int> C(MAXN + 1);
    for (auto& c : costs) ++C[c];

    int ans = 0;
    for (int p = 1; p <= MAXN; ++p) {
      int cnt = min(coins / p, C[p]);
      ans += cnt;
      coins -= p * cnt;
    }
    return ans;
  }
};
