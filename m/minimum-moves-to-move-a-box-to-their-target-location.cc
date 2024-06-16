const int INF = 0x3f3f3f3f;
const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
using pii = pair<int, int>;

class Solution {
public:
  int minPushBox(vector<vector<char>>& grid) {
    int N = grid.size(), M = grid[0].size();

    int bx, by, sx, sy, tx, ty;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
      if (grid[i][j] == 'B') bx = i, by = j;
      if (grid[i][j] == 'S') sx = i, sy = j;
      if (grid[i][j] == 'T') tx = i, ty = j;
    }

    int cdist[N][M][N][M]; memset(cdist, 0x3f, sizeof cdist);

    deque<tuple<int, int, int, int>> q;
    q.push_back({bx, by, sx, sy}); cdist[bx][by][sx][sy] = 0;

    while (!q.empty()) {
      auto [cbx, cby, csx, csy] = q.front(); q.pop_front();

      // move player
      for (int k = 0; k < 4; ++k) {
        int nsx = csx + dx[k], nsy = csy + dy[k];
        if (nsx < 0 || nsx >= N || nsy < 0 || nsy >= M) continue;
        if (grid[nsx][nsy] == '#') continue;
        if (nsx == cbx && nsy == cby) continue;
        if (cdist[cbx][cby][nsx][nsy] <= cdist[cbx][cby][csx][csy]) continue;

        cdist[cbx][cby][nsx][nsy] = cdist[cbx][cby][csx][csy];
        q.push_front({cbx, cby, nsx, nsy});
      }

      // if adjacent, push box
      if (abs(cbx - csx) + abs(cby - csy) == 1) {
        int nbx = cbx + (cbx - csx), nby = cby + (cby - csy);
        if (nbx < 0 || nbx >= N || nby < 0 || nby >= M) continue;
        if (grid[nbx][nby] == '#') continue;
        if (cdist[nbx][nby][cbx][cby] <= cdist[cbx][cby][csx][csy] + 1) continue;

        cdist[nbx][nby][cbx][cby] = cdist[cbx][cby][csx][csy] + 1;
        q.push_back({nbx, nby, cbx, cby});
      }
    }

    int ans = INF;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
      ans = min(ans, cdist[tx][ty][i][j]);
    }
    if (ans == INF) ans = -1;
    return ans;
  }
};
