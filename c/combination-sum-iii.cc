class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;

    for (int state = 1; state < (1 << 9); state++) {
      if (__builtin_popcount(state) == k) {
        vector<int> cur;
        for (int j = 1; j <= 9; j++) if (state & (1 << (j - 1))) cur.push_back(j);

        if (accumulate(cur.begin(), cur.end(), 0) == n) res.push_back(cur);
      }
    }

    return res;
  }
};
