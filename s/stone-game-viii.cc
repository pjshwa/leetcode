#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int stoneGameVIII(vector<int>& stones) {
    int N = stones.size();
    vector<int> P(N); P[0] = stones[0];
    for (int i = 1; i < N; ++i) P[i] = P[i - 1] + stones[i];

    vector<vector<int>> dp(N, vector<int>(2, 0));
    dp[N - 1][0] = P[N - 1]; dp[N - 1][1] = -P[N - 1];
    for (int i = N - 2; i >= 1; --i) {
      dp[i][0] = max(dp[i + 1][0], P[i] + dp[i + 1][1]);
      dp[i][1] = min(dp[i + 1][1], -P[i] + dp[i + 1][0]);
    }
    return dp[1][0];
  }
};
