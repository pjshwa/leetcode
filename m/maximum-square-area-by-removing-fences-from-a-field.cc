const int MOD = 1e9 + 7;

class Solution {
public:
  int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
    hFences.push_back(1); hFences.push_back(m);
    vFences.push_back(1); vFences.push_back(n);

    unordered_set<int> sides; long long ans = -1;
    for (int h1 : hFences) for (int h2 : hFences) {
      if (h1 == h2) continue;
      sides.insert(abs(h2 - h1));
    }
    for (int v1 : vFences) for (int v2 : vFences) {
      long long side = abs(v2 - v1);
      if (sides.count(side)) ans = max(ans, side * side);
    }
    return ans % MOD;
  }
};
