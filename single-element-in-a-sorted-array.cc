class Solution {
public:
  int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = n;
    while (l < r) {
      int m = (l + r) / 2;
      if (m == n - 1) {
        if (m == 0 || nums[m] != nums[m - 1]) return nums[m];
        else r = m;
      }
      else if (m & 1) {
        if (nums[m] == nums[m - 1]) l = m + 1;
        else r = m;
      }
      else {
        if (nums[m] == nums[m + 1]) l = m + 1;
        else r = m;
      }
    }
    return nums[l];
  }
};
