class Solution {
public:
  vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int N = nums.size(), xor_sum = 0;
    for (int e : nums) xor_sum ^= e;

    vector<int> res;
    for (int i = 0; i < N; ++i) {
      int k = 0;
      for (int b = 0; b < maximumBit; ++b) {
        if (!(xor_sum & (1 << b))) k |= 1 << b;
      }
      res.push_back(k);
      xor_sum ^= nums.back(); nums.pop_back();
    }
    return res;
  }
};
