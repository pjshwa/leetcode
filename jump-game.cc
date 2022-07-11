class Solution {
public:
  bool canJump(vector<int>& nums) {
    int i = 0, reach = 0, n = nums.size();
    for (int i = 0; i < n && i <= reach; i++) {
      reach = max(reach, i + nums[i]);
    }
    return i == n;
  }
};
