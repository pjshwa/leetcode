class Solution {
public:
  int maxWidthOfVerticalArea(vector<vector<int>>& points) {
    sort(points.begin(), points.end());
    int ans = 0, N = points.size();
    for (int i = 1; i < N; ++i) {
      int x1 = points[i - 1][0], x2 = points[i][0];
      ans = max(ans, x2 - x1);
    }
    return ans;
  }
};
