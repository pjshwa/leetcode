class Solution {
public:
  int minOperations(vector<int>& nums, int k) {
    int b = k;
    for (int e : nums) b ^= e;
    return __builtin_popcount(b);
  }
};
