class Solution {
public:
  int minGroups(vector<vector<int>>& intervals) {
    vector<pair<int, int>> ts;
    for (auto& v : intervals) {
      ts.emplace_back(v[0], -1);
      ts.emplace_back(v[1], 1);
    }
    sort(ts.begin(), ts.end());

    int dt = 0, ans = 0;
    for (auto& t : ts) {
      dt -= t.second;
      ans = max(ans, dt);
    }
    return ans;
  }
};
