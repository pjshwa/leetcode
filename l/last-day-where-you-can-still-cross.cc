const int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

class Solution {
public:
  int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
    row += 2;
    int parent[row * col], usz[row * col];
    iota(parent, parent + row * col, 0);
    fill(usz, usz + row * col, 1);

    function<int(int)> Find = [&](int x) {
      if (x != parent[x]) parent[x] = Find(parent[x]);
      return parent[x];
    };
    function<void(int, int)> Union = [&](int x, int y) {
      x = Find(x); y = Find(y);
      if (x == y) return;
      if (usz[x] < usz[y]) swap(x, y);
      parent[y] = x; usz[x] += usz[y];
    };

    int board[row][col];
    for (int i = 0; i < row; i++) {
      if (i == 0 || i == row - 1) fill(board[i], board[i] + col, 0);
      else fill(board[i], board[i] + col, 1);
    }
    for (int j = 1; j < col; j++) {
      Union(j, j - 1);
      Union((row - 1) * col + j, (row - 1) * col + j - 1);
    }

    reverse(cells.begin(), cells.end());
    int Z = cells.size();
    for (int i = 0; i < cells.size(); i++) {
      int x = cells[i][0], y = cells[i][1] - 1;
      for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (ny < 0 || ny >= col || board[nx][ny] == 1) continue;
        Union(x * col + y, nx * col + ny);
      }
      board[x][y] = 0;
      if (Find(0) == Find(row * col - 1)) return Z - 1 - i;
    }
    return 0;
  }
};
