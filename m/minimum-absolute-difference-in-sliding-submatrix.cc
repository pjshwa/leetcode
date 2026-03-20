const int INF = 0x3f3f3f3f;

class Solution {
public:
  vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
    int N = grid.size(), M = grid[0].size();
    vector<vector<int>> ans; map<int, int> S;
    auto get = [&]() {
      if (S.size() == 1) return 0;
      int res = INF;
      for (auto it = S.begin(), jt = next(S.begin()); jt != S.end(); ++it, ++jt) {
        res = min(res, abs(it->first - jt->first));
      }
      return res;
    };

    for (int i = 0; i <= N - k; ++i) {
      for (int j = 0; j < k; ++j) for (int l = 0; l < k; ++l) {
        ++S[grid[i + l][j]];
      }
      vector<int> row{get()};
      for (int j = k; j < M; ++j) {
        for (int l = 0; l < k; ++l) {
          --S[grid[i + l][j - k]];
          if (S[grid[i + l][j - k]] == 0) S.erase(grid[i + l][j - k]);
          ++S[grid[i + l][j]];
        }
        row.push_back(get());
      }
      ans.push_back(row);
      S.clear();
    }
    return ans;
  }
};
