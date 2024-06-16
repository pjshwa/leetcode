const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

class Solution {
public:
  int numberOfCleanRooms(vector<vector<int>>& room) {
    int N = room.size(), M = room[0].size();

    vector<vector<vector<int>>> cdist(N, vector<vector<int>>(M, vector<int>(4, -1)));
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0}); cdist[0][0][0] = 0;

    auto oob = [&](int i, int j) { return i < 0 || i >= N || j < 0 || j >= M; };

    while (!q.empty()) {
      auto [i, j, ldir] = q.front(); q.pop();

      int ni = i + dx[ldir], nj = j + dy[ldir];
      if (!oob(ni, nj) && room[ni][nj] == 0) {
        if (cdist[ni][nj][ldir] == -1) {
          cdist[ni][nj][ldir] = cdist[i][j][ldir] + 1;
          q.push({ni, nj, ldir});
        }
      }
      else {
        int ndir = (ldir + 1) % 4;
        if (cdist[i][j][ndir] == -1) {
          cdist[i][j][ndir] = cdist[i][j][ldir] + 1;
          q.push({i, j, ndir});
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      int f = 0;
      for (int k = 0; k < 4; ++k) f |= (cdist[i][j][k] != -1);
      ans += f;
    }
    return ans;
  }
};
