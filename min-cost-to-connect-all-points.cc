class Solution {
  int parent[1000];

  int dist(vector<int>& p1, vector<int>& p2) {
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
  }

  int Find(int x) {
    if (x == parent[x]) return x;
    else {
      int p = Find(parent[x]);
      parent[x] = p;
      return p;
    }
  }

  void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x != y) parent[y] = x;
  }

public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    for (int i = 0; i < n; i++) parent[i] = i;

    // Kruskal's algorithm
    vector<tuple<int, int, int>> ta;
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
      ta.push_back({dist(points[i], points[j]), i, j});
    }
    sort(ta.begin(), ta.end());

    int ans = 0;
    for (auto [w, x, y] : ta) {
      if (Find(x) == Find(y)) continue;
      ans += w;
      Union(x, y);
    }

    return ans;
  }
};
