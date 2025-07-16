class Solution {
public:
  int maximumLength(vector<int>& nums) {
    int N = nums.size(), ocnt = 0;
    for (int e : nums) ocnt += (e & 1);

    int ans = max(ocnt, N - ocnt), cur = 1;
    for (int i = 1; i < N; ++i) {
      cur += nums[i] % 2 != nums[i - 1] % 2;
    }
    ans = max(ans, cur);
    return ans;
  }
};
