const int MAXV = 1000, BIAS = 500;

class Solution {
public:
  int longestArithSeqLength(vector<int>& nums) {
    int n = nums.size(), ans = 0;

    int d[n][MAXV + 1];
    for (int i = 0; i < n; i++) {
      fill(d[i], d[i] + MAXV + 1, 1);
      for (int j = i - 1; j >= 0; j--) {
        int dif = nums[i] - nums[j] + BIAS;
        d[i][dif] = max(d[i][dif], d[j][dif] + 1);
        ans = max(ans, d[i][dif]);
      }
    }
    return ans;
  }
};
