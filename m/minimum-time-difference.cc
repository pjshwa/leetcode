class Solution {
public:
  int findMinDifference(vector<string>& timePoints) {
    vector<int> points;
    for (auto &time : timePoints) {
      int h = stoi(time.substr(0, 2));
      int m = stoi(time.substr(3, 2));
      points.push_back(h * 60 + m);
    }
    sort(points.begin(), points.end());
    points.push_back(points[0] + 24 * 60);

    int Z = points.size(), ans = INT_MAX;
    for (int i = 1; i < Z; ++i) ans = min(ans, points[i] - points[i - 1]);
    return ans;
  }
};
