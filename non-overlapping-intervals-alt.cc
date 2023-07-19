class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
      return a[1] < b[1];
    });

    int N = intervals.size(), ans = 0, last = INT_MIN;
    for (int i = 0; i < N; i++) {
      int s = intervals[i][0], e = intervals[i][1];
      if (last <= s) last = e;
      else ans++;
    }
    return ans;
  }
};
