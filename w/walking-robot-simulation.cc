const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

class Solution {
public:
  int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    int dir = 0, x = 0, y = 0;

    set<pair<int, int>> obs;
    for (auto &o : obstacles) obs.insert({o[0], o[1]});

    int ans = 0;
    for (int c : commands) {
      if (c == -1) dir = (dir + 1) % 4;
      else if (c == -2) dir = (dir + 3) % 4;
      else {
        for (int i = 0; i < c; ++i) {
          int nx = x + dx[dir], ny = y + dy[dir];
          if (obs.count({nx, ny})) break;
          x = nx, y = ny;
        }
        ans = max(ans, x * x + y * y);
      }
    }
    return ans;
  }
};
