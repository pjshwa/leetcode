using ll = long long;

class Solution {
public:
  int maxRotateFunction(vector<int>& nums) {
    ll N = nums.size(), sum = 0, ans = 0;
    for (int i = 0; i < N; ++i) {
      sum += nums[i];
      ans += i * nums[i];
    }
    ll cur = ans;
    for (int i = 1; i < N; ++i) {
      cur += sum - N * nums[N - i];
      ans = max(ans, cur);
    }
    return ans;
  }
};
