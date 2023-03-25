class Solution {
public:
  long long countPairs(int n, vector<vector<int>>& edges) {
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

    for (auto& e : edges) Union(e[0], e[1]);

    set<int> groups;
    for (int i = 0; i < n; i++) groups.insert(Find(i));

    long long ans = 0;
    for (int g : groups) {
      long long sz = usz[g];
      ans += sz * (n - sz);
    }
    return ans / 2;
  }
};
