class Solution {
public:
  int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    int n = piles.size();

    int d[n + 1][2001]; memset(d, 0, sizeof(d));
    for (int i = 1; i <= n; i++) {
      for (int v = 0; v <= 2000; v++) d[i][v] = d[i - 1][v];

      int add = 0;
      for (int j = 1; j <= piles[i - 1].size(); j++) {
        add += piles[i - 1][j - 1];
        for (int v = j; v <= 2000; v++) {
          d[i][v] = max(d[i][v], d[i - 1][v - j] + add);
        }
      }
    }

    return d[n][k];
  }
};
