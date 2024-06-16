const int MAXC = 60;

class Solution {
public:
  bool isPrintable(vector<vector<int>>& targetGrid) {
    int N = targetGrid.size(), M = targetGrid[0].size();

    map<int, int> maxx_c, maxy_c, minx_c, miny_c, ccnt_c;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      int color = targetGrid[i][j];

      maxx_c[color] = maxx_c.count(color) ? max(maxx_c[color], i) : i;
      maxy_c[color] = maxy_c.count(color) ? max(maxy_c[color], j) : j;
      minx_c[color] = minx_c.count(color) ? min(minx_c[color], i) : i;
      miny_c[color] = miny_c.count(color) ? min(miny_c[color], j) : j;
      ccnt_c[color]++;
    }

    // you should be able to construct a dependency graph from the colors
    vector<int> indegree(MAXC + 1, 0);
    vector<vector<int>> adj(MAXC + 1);
    for (auto [color, ccnt] : ccnt_c) {
      for (int i = minx_c[color]; i <= maxx_c[color]; ++i) for (int j = miny_c[color]; j <= maxy_c[color]; ++j) {
        if (targetGrid[i][j] != color) {
          adj[targetGrid[i][j]].push_back(color);
          indegree[color]++;
        }
      }
    }

    queue<int> q;
    for (int c = 1; c <= MAXC; ++c) {
      if (indegree[c] == 0) q.push(c);
    }

    for (int i = 0; i < MAXC; ++i) {
      if (q.empty()) return false;
      int c = q.front(); q.pop();
      for (int nc : adj[c]) {
        if (--indegree[nc] == 0) q.push(nc);
      }
    }
    return true;
  }
};
