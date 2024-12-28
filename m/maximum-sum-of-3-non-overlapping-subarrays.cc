class Solution {
  vector<vector<int>> dp;
  vector<int> P, ans;
  int N, k;

  int rec(int l, int i) {
    if (i == N) return 0;
    if (dp[l][i] != -1) return dp[l][i];

    int ret = rec(l, i + 1);
    if (l < 3 && i + k <= N) {
      ret = max(ret, rec(l + 1, i + k) + P[i + k] - P[i]);
    }
    return dp[l][i] = ret;
  }

  void trace(int l, int i) {
    if (l == 3) return;

    if (rec(l, i + 1) > rec(l + 1, i + k) + P[i + k] - P[i]) {
      trace(l, i + 1);
    } else {
      ans.push_back(i);
      trace(l + 1, i + k);
    }
  }

public:
  vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    this->N = nums.size(); this->k = k;

    P.resize(N + 1, 0);
    for (int i = 1; i <= N; ++i) P[i] = P[i - 1] + nums[i - 1];

    dp.resize(4, vector<int>(N + 1, -1));
    rec(0, 0);
    trace(0, 0);

    return ans;
  }
};
