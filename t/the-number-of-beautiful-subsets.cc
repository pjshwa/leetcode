const int MAXN = 1000;

class Solution {
public:
  int beautifulSubsets(vector<int>& nums, int k) {
    int N = nums.size(), ans = 0;

    vector<int> C(MAXN + 1, 0);
    for (int s = 0; s < 1 << N; ++s) {
      for (int i = 0; i < N; ++i) {
        if (!(s & 1 << i)) continue;
        ++C[nums[i]];
      }

      int ok = 1;
      for (int i = 0; i < N; ++i) {
        if (!(s & 1 << i)) continue;
        for (int c : {nums[i] + k, nums[i] - k}) {
          if (c < 0 || c > MAXN) continue;
          if (C[c] > 0) ok = 0;
        }
      }

      ans += ok;
      for (int i = 0; i < N; ++i) {
        if (!(s & 1 << i)) continue;
        --C[nums[i]];
      }
    }

    return ans;
  }
};
