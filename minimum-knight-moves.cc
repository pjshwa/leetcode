const int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int MAX = 660, BIAS = 330;

class Solution {
public:
  int minKnightMoves(int x, int y) {
    int cdist[MAX][MAX]; memset(cdist, 0x3f, sizeof(cdist));
    queue<pair<int, int>> q;
    q.emplace(BIAS, BIAS); cdist[BIAS][BIAS] = 0;

    while (!q.empty()) {
      auto [i, j] = q.front(); q.pop();
      if (i == x + BIAS && j == y + BIAS) return cdist[i][j];
      for (int k = 0; k < 8; ++k) {
        int ni = i + dx[k], nj = j + dy[k];
        if (ni < 0 || ni >= MAX || nj < 0 || nj >= MAX) continue;
        if (cdist[ni][nj] > cdist[i][j] + 1) {
          cdist[ni][nj] = cdist[i][j] + 1;
          q.emplace(ni, nj);
        }
      }
    }
    return -1;
  }
};
