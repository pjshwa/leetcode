const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

class Solution {
public:
  vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
    int parent[n * m], usz[n * m];
    iota(parent, parent + n * m, 0);
    fill(usz, usz + n * m, 1);

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

    set<pair<int, int>> land;
    vector<int> ans; int cur = 0;
    for (auto& pos : positions) {
      int x = pos[0], y = pos[1];
      if (land.count({x, y})) {
        ans.push_back(cur);
        continue;
      }
      ++cur;

      set<int> u_adj;
      for (int k = 0; k < 4; ++k) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        if (land.count({nx, ny})) u_adj.insert(Find(nx * n + ny));
      }

      cur -= u_adj.size(); ans.push_back(cur);
      for (int g : u_adj) Union(x * n + y, g);
      land.insert({x, y});
    }
    return ans;
  }
};
