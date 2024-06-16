using pii = pair<int, int>;

class Solution {
public:
  bool isPathCrossing(string path) {
    int x = 0, y = 0;
    set<pii> U; U.insert({x, y});

    for (auto c : path) {
      if (c == 'N') y++;
      else if (c == 'S') y--;
      else if (c == 'E') x++;
      else x--;

      if (U.count({x, y})) return true;
      U.insert({x, y});
    }

    return false;
  }
};
