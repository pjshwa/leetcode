class Solution {
public:
  int missingNumber(vector<int>& nums) {
    long long sum = accumulate(nums.begin(), nums.end(), 0LL), n = nums.size();
    return n * (n + 1) / 2 - sum;
  }
};
