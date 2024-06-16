const int MAX = 1e4, INF = 0x3f3f3f3f;

class Solution {
public:
  int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
    int cdist[MAX + 1][2]; memset(cdist, 0x3f, sizeof cdist);

    bool ban[MAX + 1]; memset(ban, 0, sizeof ban);
    for (int v : forbidden) ban[v] = true;

    queue<pair<int, int>> q;
    q.emplace(0, 0); cdist[0][0] = 0;

    while (!q.empty()) {
      auto [v, l] = q.front(); q.pop();

      if (v + a <= MAX && !ban[v + a] && cdist[v + a][0] > cdist[v][l] + 1) {
        cdist[v + a][0] = cdist[v][l] + 1;
        q.emplace(v + a, 0);
      }
      if (v - b >= 0 && !ban[v - b] && l == 0 && cdist[v - b][1] > cdist[v][l] + 1) {
        cdist[v - b][1] = cdist[v][l] + 1;
        q.emplace(v - b, 1);
      }
    }

    int ans = min(cdist[x][0], cdist[x][1]);
    return ans == INF ? -1 : ans;
  }
};
