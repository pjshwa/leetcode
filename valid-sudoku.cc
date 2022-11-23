class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i += 3) for (int j = 0; j < 9; j += 3) {
      int t[9] = {0};
      for (int k = 0; k < 3; k++) for (int l = 0; l < 3; l++) {
        if (board[i + k][j + l] == '.') continue;
        if (t[board[i + k][j + l] - '1']++) return false;
      }
    }

    for (int i = 0; i < 9; i++) {
      int t[9] = {0};
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') continue;
        if (t[board[i][j] - '1']++) return false;
      }
    }
    for (int j = 0; j < 9; j++) {
      int t[9] = {0};
      for (int i = 0; i < 9; i++) {
        if (board[i][j] == '.') continue;
        if (t[board[i][j] - '1']++) return false;
      }
    }

    return true;
  }
};
