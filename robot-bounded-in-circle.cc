const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

class Solution {
public:
  bool isRobotBounded(string instructions) {
    instructions += instructions;
    instructions += instructions;
    int dir = 0, cx = 0, cy = 0;
    for (char c : instructions) {
      if (c == 'G') cx += dx[dir], cy += dy[dir];
      else if (c == 'L') dir = (dir + 3) % 4;
      else dir = (dir + 1) % 4;
    }
    return cx == 0 && cy == 0;
  }
};
