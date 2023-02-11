const int INF = 0x3f3f3f3f;

class Solution {
public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    vector<int> Radj[n], Badj[n];
    for (auto &e : redEdges) Radj[e[0]].push_back(e[1]);
    for (auto &e : blueEdges) Badj[e[0]].push_back(e[1]);

    int cdist[n][2];
    for (int i = 0; i < n; i++) cdist[i][0] = cdist[i][1] = INF;

    queue<pair<int, int>> q;
    q.push({0, 0}); cdist[0][0] = 0;
    q.push({0, 1}); cdist[0][1] = 0;

    while (!q.empty()) {
      auto [u, c] = q.front(); q.pop();
      for (int v : (c ? Radj[u] : Badj[u])) {
        if (cdist[v][!c] > cdist[u][c] + 1) {
          cdist[v][!c] = cdist[u][c] + 1;
          q.push({v, !c});
        }
      }
    }

    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
      int d = min(cdist[i][0], cdist[i][1]);
      ans[i] = d == INF ? -1 : d;
    }
    return ans;
  }
};
