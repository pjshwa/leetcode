class Solution {
public:
  vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
    int parent[n]; iota(parent, parent + n, 0);
    function<int(int)> Find = [&](int x) {
      if (x != parent[x]) parent[x] = Find(parent[x]);
      return parent[x];
    };
    function<void(int, int)> Union = [&](int x, int y) {
      x = Find(x); y = Find(y);
      if (x != y) parent[x] = y;
    };

    for (auto& e : edges) Union(e[0], e[1]);
    int gW[n]; memset(gW, -1, sizeof(gW));
    for (auto& e : edges) {
      int g = Find(e[0]), w = e[2];
      if (gW[g] == -1) gW[g] = w;
      else gW[g] &= w;
    }

    vector<int> res;
    for (auto& q : query) {
      int x = Find(q[0]), y = Find(q[1]);
      if (x != y) res.push_back(-1);
      else res.push_back(gW[x]);
    }
    return res;
  }
};
  