class Solution {
public:
  bool canCross(vector<int>& stones) {
    int N = stones.size();

    map<int, int> inv;
    for (int i = 0; i < N; i++) inv[stones[i]] = i;

    bool dp[N][N]; memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int i = 1; i < N; i++) {

      // k = size of previous jump
      for (int k = 0; k < N; k++) {
        int pre = stones[i] - k;
        if (!inv.count(pre)) continue;

        for (int pk = k - 1; pk <= k + 1; pk++) {
          if (pk < 0 || pk >= N) continue;
          dp[i][k] |= dp[inv[pre]][pk];
        }
      }
    }

    bool ans = false;
    for (int k = 0; k < N; k++) ans |= dp[N - 1][k];
    return ans;
  }
};
