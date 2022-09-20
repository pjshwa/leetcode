class Solution {
  int d[1001][1001];
public:
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();

    memset(d, 0, sizeof(d));
    int ans = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
      if (nums1[i - 1] == nums2[j - 1]) d[i][j] = d[i - 1][j - 1] + 1;
      else d[i][j] = 0;
      ans = max(ans, d[i][j]);
    }

    return ans;
  }
};
