const int INF = 1e9 + 7;

class Solution {
  int d[101][201];
public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    int n = costs.size() / 2;
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= 2 * n; j++) {
        d[i][j] = INF;
      }
    }

    d[0][0] = 0;
    for (int i = 1; i <= costs.size(); i++) {
      for (int j = 0; j <= n; j++) {
        d[j][i] = min(d[j][i], d[j][i - 1] + costs[i - 1][0]);
        if (j) d[j][i] = min(d[j][i], d[j - 1][i - 1] + costs[i - 1][1]);
      }
    }

    return d[n][2 * n];
  }
};
