class Solution {
public:
  bool isMonotonic(vector<int>& nums) {
    int N = nums.size();

    bool inc = true, dec = true;
    for (int i = 1; i < N; ++i) {
      inc &= nums[i] >= nums[i - 1];
      dec &= nums[i] <= nums[i - 1];
    }
    return inc || dec;
  }
};
