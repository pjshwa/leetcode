class Solution {
  bool d[5000][5000];
public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    memset(d, 0, sizeof(d));
    for (int i = 0; i < n; i++) {
      d[i][i] = 1;
      if (i < n - 1) d[i][i + 1] = 1;
    }
    for (int i = 0; i < n; i++) for (int j = i + 2; j < n; j++) {
      if (d[i][j - 1] && nums[i + 1] - nums[i] == nums[j] - nums[j - 1]) d[i][j] = 1;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = i + 2; j < n; j++) ans += d[i][j];
    return ans;
  }
};
