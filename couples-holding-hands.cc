class Solution {
public:
  int minSwapsCouples(vector<int>& row) {
    int n = row.size() / 2;

    int parent[n], usz[n];
    iota(parent, parent + n, 0);
    fill(usz, usz + n, 1);

    function<int(int)> Find = [&](int x) {
      if (x != parent[x]) parent[x] = Find(parent[x]);
      return parent[x];
    };
    function<void(int, int)> Union = [&](int x, int y) {
      x = Find(x); y = Find(y);
      if (x == y) return;
      if (usz[x] < usz[y]) swap(x, y);
      parent[y] = x; usz[x] += usz[y];
    };

    for (int i = 0; i < n; i++) {
      int u = 2 * i, v = 2 * i + 1;
      Union(row[u] / 2, row[v] / 2);
    }

    set<int> groups;
    for (int i = 0; i < n; i++) groups.insert(Find(i));

    int ans = 0;
    for (int x : groups) ans += usz[x] - 1;
    return ans;
  }
};
