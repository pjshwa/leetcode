class Solution {
public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    vector<int> q[500];
    int n = mat.size(), m = mat[0].size();
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
      int k = i - j + 100;
      q[k].push_back(mat[i][j]);
    }
    for (auto& v : q) {
      sort(v.begin(), v.end());
      reverse(v.begin(), v.end());
    }

    vector<vector<int>> ans(n, vector<int>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
      int k = i - j + 100;
      ans[i][j] = q[k].back();
      q[k].pop_back();
    }

    return ans;
  }
};
