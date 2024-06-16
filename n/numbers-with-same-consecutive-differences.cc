class Solution {
  vector<int> ans;
  int cur, n, k;

  void dfs(int c, int i) {
    if (i == n) {
      ans.push_back(cur);
      return;
    }

    if (k == 0) {
      cur = cur * 10 + c;
      dfs(c, i + 1);
      cur /= 10;
    }
    else {
      for (int u : {c + k, c - k}) {
        if (u >= 0 && u < 10) {
          cur = cur * 10 + u;
          dfs(u, i + 1);
          cur /= 10;
        }
      }
    }
  }

public:
  vector<int> numsSameConsecDiff(int n, int k) {
    this->n = n;
    this->k = k;
    for (int i = 1; i <= 9; i++) {
      cur = i;
      dfs(i, 1);
    }
    return ans;
  }
};
