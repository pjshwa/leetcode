class Solution {
public:
  int countCompleteComponents(int n, vector<vector<int>>& edges) {
    vector<int> parent(n); iota(parent.begin(), parent.end(), 0);
    function<int(int)> Find = [&](int x) {
      if (x != parent[x]) parent[x] = Find(parent[x]);
      return parent[x];
    };
    function<void(int, int)> Union = [&](int x, int y) {
      x = Find(x); y = Find(y);
      if (x != y) parent[x] = y;
    };

    for (auto& e : edges) Union(e[0], e[1]);
    vector<int> gW(n), gZ(n);
    for (auto& e : edges) ++gW[Find(e[0])];
    for (int i = 0; i < n; ++i) ++gZ[Find(i)];

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (gZ[i] && gW[i] == gZ[i] * (gZ[i] - 1) / 2) ++ans;
    }
    return ans;
  }
};
