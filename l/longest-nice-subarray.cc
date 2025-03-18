const int MAXL = 31;

class Solution {
public:
  int longestNiceSubarray(vector<int>& nums) {
    int N = nums.size(), ans = 1;
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < min(N, i + MAXL); ++j) {
        int ok = 1;
        for (int k = i; k < j; ++k) ok &= !(nums[k] & nums[j]);
        if (ok) ans = max(ans, j - i + 1);
        else break;
      }
    }
    return ans;
  }
};
