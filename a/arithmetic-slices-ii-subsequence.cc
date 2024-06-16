class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    long n = nums.size();
    map<long, long> d[n];

    long ans = 0;
    for (int i = 1; i < n; i++) {
      for (int j = i - 1; j >= 0; j--) {
        long diff = (long)nums[i] - nums[j];
        d[i][diff] += d[j][diff] + 1;
      }

      for (auto [_, c] : d[i]) ans += c;
    }

    ans -= (n - 1) * n / 2;
    return ans;
  }
};
