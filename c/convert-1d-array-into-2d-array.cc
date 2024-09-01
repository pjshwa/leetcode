class Solution {
public:
  vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    if (original.size() != n * m) return {};
    swap(n, m);

    vector<vector<int>> res(n, vector<int>(m));
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i][j] = original[i * m + j];
    return res;
  }
};
