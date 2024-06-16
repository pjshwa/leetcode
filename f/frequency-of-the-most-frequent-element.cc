using ll = long long;

class Solution {
public:
  int maxFrequency(vector<int>& nums, int k) {
    int N = nums.size(), ans = 1, l = 0;
    sort(nums.begin(), nums.end());

    ll acc = 0;
    for (int i = 1; i < N; ++i) {
      acc += (ll)(nums[i] - nums[i - 1]) * (i - l);
      while (acc > k) {
        acc -= nums[i] - nums[l];
        ++l;
      }
      ans = max(ans, i - l + 1);
    }

    return ans;
  }
};
