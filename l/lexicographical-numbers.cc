class Solution {
  int N, cur = 0;
  vector<int> res;

  void dfs() {
    if (cur) res.push_back(cur);
    for (int d = 0; d < 10; ++d) {
      int nxt = cur * 10 + d, pre = cur;
      if (nxt > 0 && nxt <= N) {
        cur = nxt;
        dfs();
        cur = pre;
      }
    }
  }

public:
  vector<int> lexicalOrder(int n) {
    N = n; dfs();
    return res;
  }
};
