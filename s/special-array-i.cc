class Solution {
public:
  bool isArraySpecial(vector<int>& nums) {
    int N = nums.size();
    for (int i = 1; i < N; ++i) {
      if ((nums[i] ^ nums[i - 1]) & 1) continue;
      return false;
    }
    return true;
  }
};
