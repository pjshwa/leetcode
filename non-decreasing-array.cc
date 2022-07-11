class Solution {
public:
  bool checkPossibility(vector<int>& nums) {
    int n = nums.size();
    bool f = false;
    for (int i = 0; i < n - 1; i++) {
      if (nums[i] > nums[i + 1]) {
        if (f) return false;
        f = true;
        if (i == 0 || nums[i - 1] <= nums[i + 1]) nums[i] = nums[i + 1];
        else nums[i + 1] = nums[i];
      }
    }
    return true;
  }
};
