class Solution {
public:
  int earliestAcq(vector<vector<int>>& logs, int n) {
    sort(logs.begin(), logs.end());

    int parent[n];
    iota(parent, parent + n, 0);

    function<int(int)> Find = [&](int x) {
      if (x != parent[x]) parent[x] = Find(parent[x]);
      return parent[x];
    };
    function<void(int, int)> Union = [&](int x, int y) {
      x = Find(x); y = Find(y);
      if (x != y) parent[x] = y;
    };

    int uc = 0;
    for (auto& l : logs) {
      int t = l[0], x = l[1], y = l[2];
      if (Find(x) == Find(y)) continue;
      Union(x, y); ++uc;
      if (uc == n - 1) return t;
    }
    return -1;
  }
};
