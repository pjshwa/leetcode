using ll = long long;

class Solution {
public:
  ll maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
    ll ans = 0; vector<ll> D;
    for (int i = 0; i < nums.size(); ++i) {
      D.push_back((nums[i] ^ k) - nums[i]);
      ans += nums[i];
    }
    sort(D.begin(), D.end());

    for (int i = 1; i < D.size(); i += 2) {
      ll sum = D[i] + D[i - 1];
      if (sum > 0) ans += sum;
    }
    return ans;
  }
};
