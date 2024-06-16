class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int D[32] = {0};
    for (int e : nums) {
      for (int i = 0; i < 32; ++i) {
        D[i] += (e >> i) & 1;
      }
    }

    int ans = 0;
    for (int i = 0; i < 32; ++i) {
      ans |= (D[i] % 3) << i;
    }
    return ans;
  }
};
