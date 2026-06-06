class Solution {
public:
  vector<int> leftRightDifference(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    vector<int> ans; int N = nums.size(), lacc = 0;
    for (int i = 0; i < N; ++i) {
      int racc = sum - lacc - nums[i];
      ans.push_back(abs(lacc - racc));
      lacc += nums[i];
    }
    return ans;
  }
};
