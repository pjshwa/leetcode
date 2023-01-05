class Solution {
public:
  int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
      if (a[0] == b[0]) return a[1] < b[1];
      return a[0] < b[0];
    });

    int p = 1, n = points.size(), ans = 1, cs = points[0][0], ce = points[0][1];
    while (p < n) {
      int s = points[p][0], e = points[p][1];
      int ns = max(cs, s), ne = min(ce, e);

      if (ns <= ne) s = ns, e = ne;
      else ans++;

      cs = s; ce = e; p++;
    }

    return ans;
  }
};
