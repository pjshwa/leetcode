using pii = pair<int, int>;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    if (image[sr][sc] == newColor) return image;

    int n = image.size(), m = image[0].size();
    int old_color = image[sr][sc];

    queue<pii> q;
    q.push({sr, sc});
    image[sr][sc] = newColor;

    while (!q.empty()) {
      auto [cr, cc] = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        int nr = cr + dx[i], nc = cc + dy[i];
        if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
        if (image[nr][nc] == old_color) {
          image[nr][nc] = newColor;
          q.push({nr, nc});
        }
      }
    }

    return image;
  }
};
