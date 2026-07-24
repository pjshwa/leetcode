const int MAXN = 2048;

class Solution {
public:
  int uniqueXorTriplets(vector<int>& nums) {
    int N = nums.size(), D2[MAXN + 1] = {0}, D3[MAXN + 1] = {0};
    for (int i = 0; i < N; ++i) {
      int x = nums[i];
      for (int j = 0; j <= i; ++j) D2[x ^ nums[j]] |= 1;
      for (int v = 0; v <= MAXN; ++v) if (D2[v]) D3[v ^ x] |= 1;
    }
    int ans = 0;
    for (int v = 0; v <= MAXN; ++v) ans += D3[v];
    return ans;
  }
};
