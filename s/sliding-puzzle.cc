const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

class Solution {
  vector<vector<int>> to_board(int s) {
    vector<vector<int>> board(2, vector<int>(3));
    for (int i = 0; i < 2; ++i) for (int j = 0; j < 3; ++j) {
      board[i][j] = s % 10;
      s /= 10;
    }
    return board;
  }

  int to_state(vector<vector<int>>& board) {
    int s = 0;
    for (int i = 1; i >= 0; --i) for (int j = 2; j >= 0; --j) {
      s = s * 10 + board[i][j];
    }
    return s;
  }

public:
  int slidingPuzzle(vector<vector<int>>& board) {
    queue<int> Q;
    vector<int> cdist(1000000, INT_MAX);
    int start = to_state(board), end = 54321;
    Q.push(start); cdist[start] = 0;

    while (!Q.empty()) {
      int s = Q.front(); Q.pop();
      auto board = to_board(s);
      for (int i = 0; i < 2; ++i) for (int j = 0; j < 3; ++j) {
        if (board[i][j] != 0) continue;
        for (int k = 0; k < 4; ++k) {
          int ni = i + dx[k], nj = j + dy[k];
          if (ni < 0 || ni >= 2 || nj < 0 || nj >= 3) continue;
          swap(board[i][j], board[ni][nj]);
          int ns = to_state(board);
          if (cdist[ns] == INT_MAX) {
            cdist[ns] = cdist[s] + 1;
            Q.push(ns);
          }
          swap(board[i][j], board[ni][nj]);
        }
      }
    }

    int ans = cdist[end];
    if (ans == INT_MAX) ans = -1;
    return ans;
  }
};
