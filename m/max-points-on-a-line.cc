class Solution {
public:
  int maxPoints(vector<vector<int>>& points) {
    int n = points.size();

    int ans = 0;
    for (int i = 0; i < n; i++) {
      int ox = points[i][0], oy = points[i][1];

      int vt = 0; map<pair<int, int>, int> by_slope;
      for (int j = 0; j < n; j++) {
        if (i == j) continue;

        int x = points[j][0], y = points[j][1];
        if (x == ox) vt++;
        else {
          int num = y - oy, den = x - ox;
          int g = __gcd(num, den);
          by_slope[{num / g, den / g}]++;
        }
      }

      ans = max(ans, vt + 1);
      for (auto &p : by_slope) {
        ans = max(ans, p.second + 1);
      }
    }

    return ans;
  }
};
