class Solution {
public:
  int countComponents(int n, vector<vector<int>>& edges) {
    vector<int> parent(n);
    iota(parent.begin(), parent.end(), 0);

    function<int(int)> Find = [&](int x) {
      return parent[x] == x ? x : parent[x] = Find(parent[x]);
    };
    function<void(int, int)> Union = [&](int x, int y) {
      parent[Find(x)] = Find(y);
    };
    for (auto& e : edges) Union(e[0], e[1]);

    set<int> roots;
    for (int i = 0; i < n; ++i) roots.insert(Find(i));
    return roots.size();
  }
};
