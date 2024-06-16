class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int k = 0, n = nums.size(), l = -101;
    for (int i = 0; i < n; i++) {
      if (nums[i] != l) {
        nums[k++] = nums[i];
        l = nums[i];
      }
    }
    return k;
  }
};
