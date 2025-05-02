class SnakeGame {
  int score = 0, fi = 0, fz, width, height;
  vector<vector<int>> food, board;
  queue<pair<int, int>> snake;

  bool oob(int x, int y) {
    return x < 0 || x >= height || y < 0 || y >= width;
  }

public:
  SnakeGame(int width, int height, vector<vector<int>>& food) {
    this->width = width, this->height = height, this->food = food;
    fz = food.size();
    board.resize(height, vector<int>(width));
    board[0][0] = 1; snake.push({0, 0});
  }

  int move(string direction) {
    if (score == -1) return -1;

    auto [si, sj] = snake.back(); int ni = si, nj = sj;
    if (direction == "U") --ni;
    if (direction == "D") ++ni;
    if (direction == "L") --nj;
    if (direction == "R") ++nj;
    if (oob(ni, nj)) {
      score = -1;
      return -1;
    }

    bool is_food = fi < fz && ni == food[fi][0] && nj == food[fi][1];
    if (is_food) ++score, ++fi;
    else {
      auto [ti, tj] = snake.front();
      board[ti][tj] = 0;
      snake.pop();
    }

    if (board[ni][nj] == 1) {
      score = -1;
      return -1;
    }
    board[ni][nj] = 1; snake.push({ni, nj});
    return score;
  }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
