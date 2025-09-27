double area(int p0x, int p0y, int p1x, int p1y, int p2x, int p2y) {
  return abs((p1x - p0x) * (p2y - p0y) - (p2x - p0x) * (p1y - p0y)) / 2.0;
}

class Solution {
public:
  double largestTriangleArea(vector<vector<int>>& points) {
    int N = points.size(); double ans = 0;
    for (int i = 0; i < N; ++i) for (int j = i + 1; j < N; ++j) for (int k = j + 1; k < N; ++k)
      ans = max(ans,
        area(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]));
    return ans;
  }
};
