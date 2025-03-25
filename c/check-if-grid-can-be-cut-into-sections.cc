class Solution {
public:
  bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
    int N = rectangles.size();
    {
      sort(rectangles.begin(), rectangles.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
      });
      int cnt = 0, maxx = 0;
      for (int i = 0; i < N; ++i) {
        int sx = rectangles[i][0], ex = rectangles[i][2];
        if (i > 0 && maxx <= sx) ++cnt;
        maxx = max(maxx, ex);
      }
      if (cnt >= 2) return true;
    }
    {
      sort(rectangles.begin(), rectangles.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
      });
      int cnt = 0, maxy = 0;
      for (int i = 0; i < N; ++i) {
        int sy = rectangles[i][1], ey = rectangles[i][3];
        if (i > 0 && maxy <= sy) ++cnt;
        maxy = max(maxy, ey);
      }
      if (cnt >= 2) return true;
    }
    return false;
  }
};
