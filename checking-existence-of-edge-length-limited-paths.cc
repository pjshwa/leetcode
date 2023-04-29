class Solution {
public:
  vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
    int z = edgeList.size(), q = queries.size();
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

    sort(edgeList.begin(), edgeList.end(), [](const auto& a, const auto& b) {
      return a[2] < b[2];
    });

    auto queries_wii = queries;
    for (int i = 0; i < q; i++) queries_wii[i].push_back(i);
    sort(queries_wii.begin(), queries_wii.end(), [](const auto& a, const auto& b) {
      return a[2] < b[2];
    });

    vector<bool> ans(q); int j = 0;
    for (auto& vv : queries_wii) {
      int u = vv[0], v = vv[1], l = vv[2], i = vv[3];
      while (j < z && edgeList[j][2] < l) {
        int x = edgeList[j][0], y = edgeList[j][1];
        Union(x, y); j++;
      }
      ans[i] = Find(u) == Find(v);
    }
    return ans;
  }
};
