using ll = long long;

class Solution {
  ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
  }

public:
  int subarrayLCM(vector<int>& nums, int k) {
    int n = nums.size(), ans = 0;
    for (int i = 0; i < n; ++i) {
      ll l = nums[i];
      if (l == k) ans++;
      for (int j = i + 1; j < n; j++) {
        l = lcm(l, nums[j]);
        if (l > k) break;
        if (l == k) ans++;
      }
    }
    return ans;
  }
};
