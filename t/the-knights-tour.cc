const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

class Solution {
  int vis[5][5];

public:
  vector<vector<int>> tourOfKnight(int m, int n, int r, int c) {
    vector<vector<int>> cur, ans; int flag = 0;
    function<void(int, int)> dfs = [&](int i, int j) {
      if (flag) return;
      vis[i][j] = 1;
      cur.push_back({i, j});
      for (int k = 0; k < 8; ++k) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (ni >= 0 && ni < m && nj >= 0 && nj < n && !vis[ni][nj]) {
          dfs(ni, nj);
        }
      }
      if (cur.size() == m * n) {
        ans = cur;
        flag = 1;
      }
      vis[i][j] = 0;
      cur.pop_back();
    };

    dfs(r, c);
    vector<vector<int>> board(m, vector<int>(n));
    for (int i = 0; i < m * n; ++i) board[ans[i][0]][ans[i][1]] = i;
    return board;
  }
};
