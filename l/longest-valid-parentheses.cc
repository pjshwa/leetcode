class Solution {
  int dp[30001];
public:
  int longestValidParentheses(string s) {
    int n = s.size(), ans = 0;
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i < n; i++) {
      if (s[i] == ')') {
        if (s[i - 1] == '(') dp[i] = 2 + (i - 2 >= 0 ? dp[i - 2] : 0);
        else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
          dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0);
        }
        ans = max(ans, dp[i]);
      }
    }
    return ans;
  }
};
