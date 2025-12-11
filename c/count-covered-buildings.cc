const int MAXN = 1e5;
vector<int> H[MAXN + 1], V[MAXN + 1];

class Solution {
public:
  int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
    for (int i = 1; i <= n; ++i) {
      H[i].clear();
      V[i].clear();
    }
    for (auto& building : buildings) {
      int x = building[0], y = building[1];
      H[x].push_back(y);
      V[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
      sort(H[i].begin(), H[i].end());
      sort(V[i].begin(), V[i].end());
    }

    int ans = 0;
    for (auto& building : buildings) {
      int x = building[0], y = building[1];
      if (x == V[y].front() || x == V[y].back() ||
          y == H[x].front() || y == H[x].back()) {
        continue;
      }
      ++ans;
    }
    return ans;
  }
};
