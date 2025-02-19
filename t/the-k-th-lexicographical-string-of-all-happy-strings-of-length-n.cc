class Solution {
  string cur, ans;
  int cnt = 0, n, k;

  void dfs(int i) {
    if (i == n) {
      if (++cnt == k) ans = cur;
      return;
    }
    for (char c = 'a'; c <= 'c'; ++c) {
      if (i == 0 || c != cur[i - 1]) {
        cur.push_back(c);
        dfs(i + 1);
        cur.pop_back();
      }
    }
  }

public:
  string getHappyString(int n, int k) {
    this->n = n; this->k = k;
    dfs(0);
    return ans;
  }
};
