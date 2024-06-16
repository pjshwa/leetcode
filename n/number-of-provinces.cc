class Solution {
public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size(), ans = n;
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

    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
      if (isConnected[i][j] && Find(i) != Find(j)) Union(i, j), ans--;
    }
    return ans;
  }
};
