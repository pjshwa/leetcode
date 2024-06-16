class Solution {
public:
  int findNumberOfLIS(vector<int>& nums) {
    int N = nums.size();

    int d[N], maxd = 0;
    for (int i = 0; i < N; i++) {
      d[i] = 1;
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) d[i] = max(d[i], d[j] + 1);
      }
      maxd = max(maxd, d[i]);
    }

    int d2[N][N + 1]; memset(d2, -1, sizeof(d2));
    function<int(int, int)> dfs = [&](int i, int v) {
      if (d2[i][v] != -1) return d2[i][v];
      if (v == 1) return d2[i][v] = 1;

      int ret = 0;
      for (int j = 0; j < i; j++) {
        if (d[j] == v - 1 && nums[j] < nums[i]) ret += dfs(j, v - 1);
      }
      return d2[i][v] = ret;
    };

    int ans = 0;
    for (int i = 0; i < N; i++) {
      if (d[i] == maxd) ans += dfs(i, maxd);
    }
    return ans;
  }
};
