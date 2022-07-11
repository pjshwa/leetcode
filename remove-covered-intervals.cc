class Solution {
public:
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
      if (a[0] == b[0]) return a[1] > b[1];
      return a[0] < b[0];
    });

    stack<int> et;
    for (auto& v : intervals) {
      if (et.empty() || et.top() < v[1]) et.push(v[1]);
    }

    return et.size();
  }
};
