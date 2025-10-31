class Solution {
public:
  vector<int> getSneakyNumbers(vector<int>& nums) {
    int N = nums.size(); vector<int> ans;
    sort(nums.begin(), nums.end());
    for (int i = 1; i < N; ++i) {
      if (nums[i] != nums[i - 1]) continue;
      ans.push_back(nums[i]);
    }
    return ans;
  }
};
