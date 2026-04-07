class Robot {
  const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
  const string dirs[4] = {"East", "North", "West", "South"};
  int W, H, x = 0, y = 0, d = 0;

  bool oob(int x, int y) {
    return x < 0 || x >= W || y < 0 || y >= H;
  }

public:
  Robot(int width, int height) {
    W = width, H = height;
  }

  void step(int num) {
    while (1) {
      if (num == 0) break;
      int nx = x + dx[d], ny = y + dy[d];
      if (oob(nx, ny)) break;
      x = nx, y = ny, --num;
    }
    num %= (W + H - 2) * 2;
    while (num--) {
      int nx = x + dx[d], ny = y + dy[d];
      if (oob(nx, ny)) {
        d = (d + 1) % 4;
        nx = x + dx[d], ny = y + dy[d];
      }
      x = nx, y = ny;
    }
  }

  vector<int> getPos() {
    return {x, y};
  }

  string getDir() {
    return dirs[d];
  }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
