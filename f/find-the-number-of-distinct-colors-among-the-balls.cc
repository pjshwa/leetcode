class Solution {
public:
  vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    vector<int> res;
    unordered_map<int, int> O, C; int cnt = 0;
    auto inc = [&](int x, int v) {
      if (O[x] == 0) ++cnt;
      O[x] += v;
      if (O[x] == 0) --cnt;
    };

    for (auto& q : queries) {
      int x = q[0], y = q[1];
      if (C[x]) inc(C[x], -1);
      C[x] = y; inc(y, 1);
      res.push_back(cnt);
    }
    return res;
  }
};
