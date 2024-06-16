class Solution {
public:
  bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    int parent[2 * n];
    iota(parent, parent + 2 * n, 0);

    function<int(int)> Find = [&](int x) {
      if (x != parent[x]) parent[x] = Find(parent[x]);
      return parent[x];
    };
    function<void(int, int)> Union = [&](int x, int y) {
      x = Find(x); y = Find(y);
      if (x != y) parent[x] = y;
    };

    for (auto& v : dislikes) {
      int x = v[0] - 1, y = v[1] - 1;
      if (Find(x) == Find(y)) return false;
      Union(x, n + y);
      Union(n + x, y);
    }
    return true;
  }
};
