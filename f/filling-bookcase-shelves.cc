class Solution {
public:
  int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    int N = books.size();
    vector<int> dp(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
      int tot_w = books[i - 1][0], tot_h = books[i - 1][1];
      dp[i] = dp[i - 1] + tot_h;

      for (int j = i - 1; j >= 1; --j) {
        int w = books[j - 1][0], h = books[j - 1][1];
        tot_w += w; tot_h = max(tot_h, h);
        if (tot_w > shelfWidth) break;
        dp[i] = min(dp[i], dp[j - 1] + tot_h);
      }
    }
    return dp[N];
  }
};
