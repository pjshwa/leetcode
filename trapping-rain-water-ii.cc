using tii = tuple<int, int, int>;
const int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

class Solution {
public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    int N = heightMap.size(), M = heightMap[0].size();

    int cdist[N][M]; memset(cdist, 0x3f, sizeof(cdist));
    priority_queue<tii, vector<tii>, greater<tii>> pq;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
      if (i == 0 || i == N - 1 || j == 0 || j == M - 1) {
        pq.push({heightMap[i][j], i, j});
        cdist[i][j] = heightMap[i][j];
      }
    }

    while (!pq.empty()) {
      auto [h, i, j] = pq.top(); pq.pop();

      for (int k = 0; k < 4; k++) {
        int ni = i + dx[k], nj = j + dy[k], nw;
        if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
        nw = max(h, heightMap[ni][nj]);

        if (nw < cdist[ni][nj]) {
          cdist[ni][nj] = nw;
          pq.push({nw, ni, nj});
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
      ans += cdist[i][j] - heightMap[i][j];
    }
    return ans;
  }
};
