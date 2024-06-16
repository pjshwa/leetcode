class Solution {
public:
  int minSwap(vector<int>& nums1, vector<int>& nums2) {
    int N = nums1.size();

    // dp[i][j] = cost til i-th index, j = 0 means no swap, j = 1 means swap
    vector<vector<int>> dp(N, vector<int>(2, INT_MAX));
    dp[0][0] = 0; dp[0][1] = 1;

    for (int i = 1; i < N; ++i) {
      int pa = nums1[i - 1], pb = nums2[i - 1];
      for (int pj = 0; pj < 2; ++pj) {
        int na = nums1[i], nb = nums2[i];
        for (int nj = 0; nj < 2; ++nj) {
          if (na > pa && nb > pb) {
            dp[i][nj] = min(dp[i][nj], dp[i - 1][pj] + nj);
          }
          swap(na, nb);
        }
        swap(pa, pb);
      }
    }

    return min(dp[N - 1][0], dp[N - 1][1]);
  }
};
