class Solution {
public:
  bool canJump(vector<int>& nums) {
    int n = nums.size(), reach = nums[0];
    for (int i = 0; i < n && reach >= i; ++i) {
      reach = max(reach, i + nums[i]);
      if (reach >= n - 1) return true;
    }
    return false;
  }
};
