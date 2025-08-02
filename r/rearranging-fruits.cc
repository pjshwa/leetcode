using ll = long long;

class Solution {
public:
  long long minCost(vector<int>& basket1, vector<int>& basket2) {
    unordered_map<int, int> D; int minv = 1e9;
    for (int x : basket1) ++D[x], minv = min(minv, x);
    for (int x : basket2) --D[x], minv = min(minv, x);

    vector<int> P; int N = 0;
    for (auto& [x, c] : D) {
      if (abs(c) & 1) return -1;
      for (int j = 0; j < abs(c) / 2; ++j) P.push_back(x);
    }
    sort(P.begin(), P.end());

    ll ans = 0, Z = P.size();
    assert(Z % 2 == 0);
    for (int i = 0; i < Z / 2; ++i) ans += min(P[i], 2 * minv);
    return ans;
  }
};
