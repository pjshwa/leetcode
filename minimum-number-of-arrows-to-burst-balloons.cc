class Solution {
public:
  int findMinArrowShots(vector<vector<int>>& points) {
    int ans = 0, cs, ce;
    bool first = true;
    sort(points.begin(), points.end());
    for (auto& v : points) {
      int s = v[0], e = v[1];
      if (first || s > ce) {
        ans++;
        first = false;
        cs = s;
        ce = e;
      }
      else cs = max(cs, s), ce = min(ce, e);
    }
    return ans;
  }
};
