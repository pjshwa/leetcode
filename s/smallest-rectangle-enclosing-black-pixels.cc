const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

class Solution {
public:
  int minArea(vector<vector<char>>& image, int x, int y) {
    int minx = x, maxx = x, miny = y, maxy = y;
    int N = image.size(), M = image[0].size();
    vector<vector<bool>> vis(N, vector<bool>(M, false));
    queue<pair<int, int>> q;
    q.push({x, y}); vis[x][y] = true;
    while (!q.empty()) {
      auto [x, y] = q.front(); q.pop();
      minx = min(minx, x); maxx = max(maxx, x);
      miny = min(miny, y); maxy = max(maxy, y);
      for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M || vis[nx][ny]) continue;
        if (image[nx][ny] == '1') {
          q.push({nx, ny});
          vis[nx][ny] = true;
        }
      }
    }
    return (maxx - minx + 1) * (maxy - miny + 1);
  }
};
