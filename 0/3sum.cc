class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
      if (nums[i] > 0) break;
      if (i > 0 && nums[i] == nums[i - 1]) continue;

      int sp = i + 1, ep = n - 1;
      while (sp < ep) {
        int sum = nums[i] + nums[sp] + nums[ep];
        if (sum < 0) sp++;
        else if (sum > 0) ep--;
        else {
          ans.push_back({nums[i], nums[sp], nums[ep]});
          while (sp < ep && nums[sp] == nums[sp + 1]) sp++;
          while (sp < ep && nums[ep] == nums[ep - 1]) ep--;
          sp++;
          ep--;
        }
      }
    }

    return ans;
  }
};
