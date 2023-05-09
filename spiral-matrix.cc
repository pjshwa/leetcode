const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    bool vis[n][m];
    memset(vis, 0, sizeof(vis));

    vector<int> ans;
    int cx = 0, cy = 0, d = 0;
    while (ans.size() < n * m) {
      ans.push_back(matrix[cx][cy]);
      vis[cx][cy] = true;
      int nx = cx + dx[d], ny = cy + dy[d];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny]) {
        d = (d + 1) % 4;
        nx = cx + dx[d], ny = cy + dy[d];
      }
      cx = nx, cy = ny;
    }
    return ans;
  }
};
