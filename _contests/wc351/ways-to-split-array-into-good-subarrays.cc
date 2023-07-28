const int MOD = 1e9 + 7;

class Solution {
public:
  int numberOfGoodSubarraySplits(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum == 0) return 0;
    if (sum == 1) return 1;

    vector<int> P;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 1) P.push_back(i);
    }

    long long ans = 1;
    for (int i = 1; i < P.size(); i++) {
      ans = (ans * (P[i] - P[i - 1])) % MOD;
    }
    return ans;
  }
};
