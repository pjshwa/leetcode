const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

class Solution {
public:
  bool exist(vector<vector<char>>& board, string word) {
    int N = board.size(), M = board[0].size();
    vector<vector<bool>> vis(N, vector<bool>(M, false));

    function<bool(int, int, int)> dfs = [&](int x, int y, int idx) {
      if (idx == word.size()) return true;
      if (x < 0 || x >= N || y < 0 || y >= M || vis[x][y] || board[x][y] != word[idx]) return false;

      vis[x][y] = true;
      for (int k = 0; k < 4; ++k) {
        if (dfs(x + dx[k], y + dy[k], idx + 1)) return true;
      }
      vis[x][y] = false;

      return false;
    };

    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) if (dfs(i, j, 0)) return true;
    return false;
  }
};
