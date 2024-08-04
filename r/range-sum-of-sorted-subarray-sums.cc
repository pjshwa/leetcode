const int MOD = 1e9 + 7;

class Solution {
public:
  int rangeSum(vector<int>& nums, int n, int left, int right) {
    vector<int> E;
    for (int i = 0; i < n; ++i) {
      int sum = 0;
      for (int j = i; j < n; ++j) {
        sum += nums[j];
        E.push_back(sum);
      }
    }
    sort(E.begin(), E.end());

    int ans = 0;
    for (int i = left - 1; i < right; ++i) ans = (ans + E[i]) % MOD;
    return ans;
  }
};
