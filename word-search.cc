const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

class Solution {
public:
  bool exist(vector<vector<char>>& board, string word) {
    int n = board.size(), m = board[0].size();
    auto dfs = [&](auto&& dfs, int i, int j, int c) -> bool {
      if (c + 1 == word.size()) return true;

      board[i][j] = '#';
      for (int k = 0; k < 4; ++k) {
        int ni = i + dx[k], nj = j + dy[k];
        if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

        if (board[ni][nj] == word[c + 1] && dfs(dfs, ni, nj, c + 1)) return true;
      }
      board[i][j] = word[c];
      return false;
    };

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (board[i][j] == word[0] && dfs(dfs, i, j, 0)) return true;
      }
    }

    return false;
  }
};
