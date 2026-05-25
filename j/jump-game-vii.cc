class Solution {
public:
  bool canReach(string s, int minJump, int maxJump) {
    int N = s.size();
    vector<int> dp(N + 1); dp[1] = 1;
    auto get = [&](int i) {
      if (i < 0 || i > N) return 0;
      return dp[i];
    };
    for (int i = 2; i <= N; ++i) {
      int v = get(i - minJump) - get(i - maxJump - 1);
      dp[i] = dp[i - 1] + (s[i - 1] == '0' && v > 0);
    }
    return dp[N] - dp[N - 1];
  }
};
