class Solution {
  int C[51]{}, target;
  vector<int> cur;
  vector<vector<int>> res;

  void dfs(int i, int acc) {
    if (acc == target) {
      res.push_back(cur);
      return;
    } else if (i > target) {
      return;
    }

    for (int c = 0; c <= C[i]; ++c) {
      int nacc = acc + i * c;
      if (nacc > target) break;

      for (int j = 0; j < c; ++j) cur.push_back(i);
      dfs(i + 1, nacc);
      for (int j = 0; j < c; ++j) cur.pop_back();
    }
  }

public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    this->target = target;
    for (int e : candidates) ++C[e];
    dfs(1, 0);
    return res;
  }
};
