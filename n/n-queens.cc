class Solution {
  bool col[9], diag1[20], diag2[20];
  int n;
  vector<vector<string>> ans;
  vector<int> cur;

  void dfs(int i) {
    if (i == n) {
      vector<string> res;
      for (int l = 0; l < n; l++) {
        string row = "";
        for (int j = 0; j < n; j++) {
          if (cur[l] == j) row.push_back('Q');
          else row.push_back('.');
        }
        res.push_back(row);
      }
      ans.push_back(res);
      return;
    }

    for (int j = 0; j < n; j++) {
      if (col[j] || diag1[i + j] || diag2[i - j + n - 1]) continue;
      col[j] = diag1[i + j] = diag2[i - j + n - 1] = true;
      cur.push_back(j);
      dfs(i + 1);
      cur.pop_back();
      col[j] = diag1[i + j] = diag2[i - j + n - 1] = false;
    }

  }
public:
  vector<vector<string>> solveNQueens(int n) {
    memset(col, 0, sizeof(col));
    memset(diag1, 0, sizeof(diag1));
    memset(diag2, 0, sizeof(diag2));

    this->n = n;
    dfs(0);
    return ans;
  }
};
