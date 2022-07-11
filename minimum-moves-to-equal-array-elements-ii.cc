using ll = long long;

class Solution {
public:
  int minMoves2(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int n = nums.size();

    ll ans = 0;
    for (int i = 1; i < n; i++) ans += nums[i] - nums[0];

    ll cur = ans;
    for (int i = 1; i < n; i++) {
      ll right = n - i, diff = nums[i] - nums[i - 1];

      cur -= right * diff;
      cur += i * diff;

      ans = min(ans, cur);
    }

    return ans;
  }
};
