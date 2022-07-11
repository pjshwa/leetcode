const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

class Solution {
public:
  
  void gameOfLife(vector<vector<int>>& board) {
    int n = board.size(), m = board[0].size();
    auto temp = board;

    for (int i=0; i < n; i++) for(int j=0; j < m; j++) {
      int neigh = 0;
      for (int k = 0; k < 8; k++) {
        int x = i + dx[k], y = j + dy[k];
        if (x >= 0 && x < n && y >= 0 && y < m) neigh += board[x][y];
      }
      if(board[i][j] == 0) {
        if(neigh == 3) temp[i][j] = 1;
      }
      else {
        if(neigh < 2 || neigh > 3) temp[i][j] = 0;
      }
    }

    board = temp;
  }
};
