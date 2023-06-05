class Solution {
public:
  bool checkStraightLine(vector<vector<int>>& coordinates) {
    int x1 = coordinates[0][0], y1 = coordinates[0][1];
    int x2 = coordinates[1][0], y2 = coordinates[1][1];

    int n = coordinates.size();
    for (int i = 2; i < n; i++) {
      int x = coordinates[i][0], y = coordinates[i][1];
      if ((y2 - y1) * (x - x1) != (y - y1) * (x2 - x1)) return false;
    }
    return true;
  }
};
