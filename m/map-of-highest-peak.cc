const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

class Solution {
public:
  vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int N = isWater.size(), M = isWater[0].size();
    vector<vector<int>> cdist(N, vector<int>(M, -1));
    queue<pair<int, int>> Q;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      if (isWater[i][j]) cdist[i][j] = 0, Q.push({i, j});
    }
    while (!Q.empty()) {
      auto [i, j] = Q.front(); Q.pop();
      for (int k = 0; k < 4; ++k) {
        int ni = i + dx[k], nj = j + dy[k];
        if (ni < 0 || ni >= N || nj < 0 || nj >= M || cdist[ni][nj] != -1) continue;
        cdist[ni][nj] = cdist[i][j] + 1;
        Q.push({ni, nj});
      }
    }
    return cdist;
  }
};
