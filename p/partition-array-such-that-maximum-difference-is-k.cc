class Solution {
public:
  int partitionArray(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int low = nums[0], ans = 1;
    for (int& e : nums) {
      if (e - low <= k) continue;
      ans++;
      low = e;
    }
    return ans;
  }
};
