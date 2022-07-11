class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;
    int ns = newInterval[0], ne = newInterval[1];
    for (auto& v : intervals) {
      int s = v[0], e = v[1];
      if (e < ns || s > ne) ans.push_back({s, e});
      else {
        ns = min(ns, s);
        ne = max(ne, e);
      }
    }
    ans.push_back({ns, ne});
    sort(ans.begin(), ans.end());
    return ans;
  }
};
