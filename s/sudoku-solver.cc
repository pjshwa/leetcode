class Solution {
  int ok = 0;

  int square(int x, int y) {
    return (x / 3) * 3 + (y / 3);
  }

  bool k_able_row(int i, char k, vector<vector<char>>& board) {
    bool able = true;
    for (int j = 0; j < 9; j++) able &= (board[i][j] != k);
    return able;
  }

  bool k_able_col(int j, char k, vector<vector<char>>& board) {
    bool able = true;
    for (int i = 0; i < 9; i++) able &= (board[i][j] != k);
    return able;
  }

  bool k_able_sqr(int s, char k, vector<vector<char>>& board) {
    bool able = true;
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
      able &= (board[(s / 3) * 3 + i][(s % 3) * 3 + j] != k);
    }
    return able;
  }

  void dfs(int i, int j, vector<vector<char>>& board) {
    if (i == 9 && j == 0) {
      ok = 1;
      return;
    }

    if (board[i][j] != '.') {
      j == 8 ? dfs(i + 1, 0, board) : dfs(i, j + 1, board);
      if (ok) return;
    }
    else {
      for (char k = '1'; k <= '9'; k++) {
        if (!k_able_row(i, k, board)) continue;
        if (!k_able_col(j, k, board)) continue;
        if (!k_able_sqr(square(i, j), k, board)) continue;

        board[i][j] = k;
        j == 8 ? dfs(i + 1, 0, board) : dfs(i, j + 1, board);
        if (ok) return;

        board[i][j] = '.';
      }
    }
  }

public:
  void solveSudoku(vector<vector<char>>& board) {
    dfs(0, 0, board);
  }
};
