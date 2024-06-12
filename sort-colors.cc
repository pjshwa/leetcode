class Solution {
public:
  void sortColors(vector<int>& nums) {
    int N = nums.size();
    for (int i = 0; i < N; ++i) for (int j = i + 1; j < N; ++j) {
      if (nums[i] > nums[j]) swap(nums[i], nums[j]);
    }
  }
};
