class Solution {
public:
  int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    vector<vector<char>> board(m, vector<char>(n, '.'));
    for (auto& guard : guards) board[guard[0]][guard[1]] = 'G';
    for (auto& wall : walls) board[wall[0]][wall[1]] = 'W';

    for (int i = 0; i < m; ++i) {
      int g = 0;
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 'W') g = 0;
        else if (board[i][j] == 'G') g = 1;
        else if (g == 1) vis[i][j] = true;
      }
      g = 0;
      for (int j = n - 1; j >= 0; --j) {
        if (board[i][j] == 'W') g = 0;
        else if (board[i][j] == 'G') g = 1;
        else if (g == 1) vis[i][j] = true;
      }
    }
    for (int j = 0; j < n; ++j) {
      int g = 0;
      for (int i = 0; i < m; ++i) {
        if (board[i][j] == 'W') g = 0;
        else if (board[i][j] == 'G') g = 1;
        else if (g == 1) vis[i][j] = true;
      }
      g = 0;
      for (int i = m - 1; i >= 0; --i) {
        if (board[i][j] == 'W') g = 0;
        else if (board[i][j] == 'G') g = 1;
        else if (g == 1) vis[i][j] = true;
      }
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
      if (!vis[i][j] && board[i][j] == '.') ++ans;
    }
    return ans;
  }
};
