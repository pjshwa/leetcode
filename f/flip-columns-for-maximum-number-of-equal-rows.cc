class Solution {
public:
  int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    for (auto& row : matrix) {
      if (row[0] == 0) continue;
      for (auto& e : row) e ^= 1;
    }

    map<vector<int>, int> m; int ans = 0;
    for (auto& row : matrix) ++m[row], ans = max(ans, m[row]);
    return ans;
  }
};
