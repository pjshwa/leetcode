using ll = long long;

class Solution {
public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    map<ll, int> P; P[0] = -1;
    ll N = nums.size(), acc = 0, ans = 0;
    for (ll i = 0; i < N; ++i) {
      acc += nums[i];
      if (!P.count(acc)) P[acc] = i;
      if (P.count(acc - k)) ans = max(ans, i - P[acc - k]);
    }
    return ans;
  }
};
