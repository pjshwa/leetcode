class Solution {
  int d[100];
public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    int ans = 0, cur = 0;

    memset(d, 0, sizeof(d));
    for (int i = 2; i < n - 1; i++) {
      d[i] = max(d[i - 2] + nums[i], d[i - 1]);
      cur = max(cur, d[i]);
    }
    ans = cur + nums[0];

    memset(d, 0, sizeof(d));
    cur = d[1] = nums[1];
    for (int i = 2; i < n; i++) {
      d[i] = max(d[i - 2] + nums[i], d[i - 1]);
      cur = max(cur, d[i]);
    }
    ans = max(ans, cur);

    return ans;
  }
};
