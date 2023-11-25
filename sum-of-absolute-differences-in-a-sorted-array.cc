class Solution {
public:
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int N = nums.size();

    vector<int> ans(N, 0);
    for (int i = 1; i < N; ++i) ans[0] += nums[i] - nums[0];
    for (int i = 1; i < N; ++i) {
      ans[i] = ans[i - 1];

      int dif = nums[i] - nums[i - 1];
      ans[i] += dif * (2 * i - N);
    }
    return ans;
  }
};
