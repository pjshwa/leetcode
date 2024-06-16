class Solution {
public:
  int minExtraChar(string s, vector<string>& dictionary) {
    int n = s.size();

    int dp[n + 1]; dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      dp[i] = dp[i - 1] + 1;
      for (string& word : dictionary) {
        int wsz = word.size();
        if (i >= wsz && word == s.substr(i - wsz, wsz)) {
          dp[i] = min(dp[i], dp[i - wsz]);
        }
      }
    }

    return dp[n];
  }
};
