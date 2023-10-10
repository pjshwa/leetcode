const int INF = 0x3f3f3f3f;
const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};

class Solution {
public:
  int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
    int n = maze.size(), m = maze[0].size();
    int si = start[0], sj = start[1], ei = destination[0], ej = destination[1];

    // pos i, pos j, direction (static: 4)
    deque<tuple<int, int, int>> q;
    int cdist[n][m][5]; memset(cdist, 0x3f, sizeof(cdist));
    q.push_back({si, sj, 4}); cdist[si][sj][4] = 0;

    while (!q.empty()) {
      auto [i, j, d] = q.front(); q.pop_front();

      if (d == 4) {
        for (int k = 0; k < 4; ++k) {
          if (cdist[i][j][k] > cdist[i][j][d]) {
            cdist[i][j][k] = cdist[i][j][d];
            q.push_front({i, j, k});
          }
        }
      }
      else {
        int ni = i + dx[d], nj = j + dy[d], nd = d;

        // ball stops
        if (ni < 0 || ni >= n || nj < 0 || nj >= m || maze[ni][nj] == 1) {
          if (cdist[i][j][4] > cdist[i][j][d]) {
            cdist[i][j][4] = cdist[i][j][d];
            q.push_front({i, j, 4});
          }
        }
        else {
          if (cdist[ni][nj][nd] > cdist[i][j][d] + 1) {
            cdist[ni][nj][nd] = cdist[i][j][d] + 1;
            q.push_back({ni, nj, nd});
          }
        }
      }

    }

    int ans = cdist[ei][ej][4];
    if (ans == INF) ans = -1;
    return ans;
  }
};
