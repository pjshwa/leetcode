class Solution {
public:
  int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int ans = 0;
    for (int i = 1; i < points.size(); ++i) {
      int ax = points[i - 1][0], ay = points[i - 1][1];
      int bx = points[i][0], by = points[i][1];
      ans += max(abs(ax - bx), abs(ay - by));
    }
    return ans;
  }
};
