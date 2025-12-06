const int MOD = 1e9 + 7;

class Solution {
public:
  int countPartitions(vector<int>& nums, int k) {
    int N = nums.size(), l = 0;
    vector<int> dp(N + 1, 1); multiset<int> run;

    for (int r = 1; r <= N; ++r) {
      run.insert(nums[r - 1]);
      while (*run.rbegin() - *run.begin() > k) {
        run.erase(run.find(nums[l++]));
      }
      int sum = dp[r - 1];
      if (l) sum = (sum - dp[l - 1] + MOD) % MOD;
      dp[r] = (sum + dp[r - 1]) % MOD;
    }
    return (dp[N] - dp[N - 1] + MOD) % MOD;
  }
};
