class Solution {
public:
  int reductionOperations(vector<int>& nums) {
    int N = nums.size();
    sort(nums.begin(), nums.end());

    int ans = 0, add = 0;
    for (int i = 1; i < N; ++i) {
      if (nums[i] > nums[i - 1]) ++add;
      ans += add;
    }
    return ans;
  }
};
