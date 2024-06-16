using ll = long long;

class Solution {
public:
  ll subsequenceSumOr(vector<int>& nums) {
    ll ans = 0, N = nums.size();
    for (int b = 0; b < 50; ++b) {
      ll r = 0, sum = 0, tar = 1LL << b;
      for (int l = 0; l < N; ++l) {
        while (r < N && sum < tar) sum += nums[r++];
        if ((sum & tar) == tar) ans |= tar;
        sum -= nums[l];
      }
    }
    return ans;
  }
};
