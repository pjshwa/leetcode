class Solution {
public:
  vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
    vector<vector<int>> ret;
    int rs = toBeRemoved[0], re = toBeRemoved[1];

    auto add_range = [&ret](int s, int e) {
      if (s < e) ret.push_back({s, e});
    };

    for (auto& v : intervals) {
      int s = v[0], e = v[1];
      int os = max(s, rs), oe = min(e, re);
      if (os < oe) {
        add_range(s, os);
        add_range(oe, e);
      }
      else add_range(s, e);
    }

    return ret;
  }
};
