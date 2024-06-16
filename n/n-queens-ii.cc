class Solution {
  bool col[9], diag1[20], diag2[20];
  int n, ans = 0;

  void dfs(int i) {
    if (i == n) {
      ans++;
      return;
    }

    for (int j = 0; j < n; j++) {
      if (col[j] || diag1[i + j] || diag2[i - j + n - 1]) continue;
      col[j] = diag1[i + j] = diag2[i - j + n - 1] = true;
      dfs(i + 1);
      col[j] = diag1[i + j] = diag2[i - j + n - 1] = false;
    }

  }

public:
  int totalNQueens(int n) {
    memset(col, 0, sizeof(col));
    memset(diag1, 0, sizeof(diag1));
    memset(diag2, 0, sizeof(diag2));

    this->n = n;
    dfs(0);
    return ans;
  }
};
