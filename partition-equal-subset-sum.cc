class Solution {
  bool d[201][20001];
public:
  bool canPartition(vector<int>& nums) {
    memset(d, 0, sizeof(d));

    int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum & 1) return false;

    d[0][0] = true;
    for (int i = 1; i <= n; ++i) {
      for (int j = 20000; j >= 0; --j) {
        d[i][j] = d[i - 1][j];
        if (j >= nums[i - 1]) d[i][j] |= d[i - 1][j - nums[i - 1]];
      }
    }

    return d[n][sum / 2];
  }
};
