using ll = long long;

class Solution {
  ll nC2(ll n) { return n * (n - 1) / 2; }

public:
  long long countBadPairs(vector<int>& nums) {
    int N = nums.size(); map<int, int> tal;
    for (int i = 0; i < N; ++i) ++tal[nums[i] - i];

    ll ans = nC2(N);
    for (auto [_, cnt] : tal) ans -= nC2(cnt);
    return ans;
  }
};
