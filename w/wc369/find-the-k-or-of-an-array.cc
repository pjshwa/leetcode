class Solution {
public:
  int findKOr(vector<int>& nums, int k) {
    int ans = 0;
    for (int b = 0; b <= 30; ++b) {
      int cnt = 0;
      for (int e : nums) {
        if (e & (1 << b)) ++cnt;
      }
      if (cnt >= k) ans |= (1 << b);
    }
    return ans;
  }
};
