class Solution {
public:
  int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
    int N = startTime.size(); vector<int> P(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
      P[i] = P[i - 1] + (endTime[i - 1] - startTime[i - 1]);
    }

    int ans = 0, L = 0;
    for (int i = k + 1; i <= N; ++i) {
      ans = max(ans, endTime[i - 1] - L - P[i] + P[i - k - 1]);
      L = endTime[i - k - 1];
    }
    ans = max(ans, eventTime - L - P[N] + P[N - k]);
    return ans;
  }
};
