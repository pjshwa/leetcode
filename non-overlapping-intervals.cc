class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
      if (a[1] == b[1]) return a[0] > b[0];
      return a[1] < b[1];
    });

    int N = intervals.size(); int ans = 0, dp[N];
    for (int i = 0; i < N; i++) {
      int l = 0, r = i;
      while (l < r) {
        int m = (l + r) / 2;

        if (intervals[m][1] <= intervals[i][0]) l = m + 1;
        else r = m;
      }

      dp[i] = (l == 0 ? 0 : dp[l - 1]) + 1;
      if (i) dp[i] = max(dp[i], dp[i - 1]);
      ans = max(ans, dp[i]);
    }

    return N - ans;
  }
};
