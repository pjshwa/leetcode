class Solution {
public:
  int numberOfPairs(vector<vector<int>>& points) {
    int N = points.size(), ans = 0;
    for (auto& v1 : points) for (auto& v2 : points) {
      int x1 = v1[0], y1 = v1[1];
      int x2 = v2[0], y2 = v2[1];

      if (x1 == x2 && y1 == y2) continue;
      if (x2 < x1 || y2 > y1) continue;

      int minx = x1, maxx = x2;
      int miny = y2, maxy = y1;
      int cnt = 0;
      for (auto& v3 : points) {
        int x3 = v3[0], y3 = v3[1];
        if (x1 == x3 && y1 == y3) continue;
        if (x2 == x3 && y2 == y3) continue;

        if (x3 >= minx && x3 <= maxx && y3 >= miny && y3 <= maxy) cnt++;
      }
      if (cnt == 0) ++ans;
    }
    return ans;
  }
};
