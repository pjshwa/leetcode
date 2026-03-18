const int dx[4] = {1, 1, -1, -1};
const int dy[4] = {1, -1, 1, -1};

class Solution {
public:
  vector<int> getBiggestThree(vector<vector<int>>& grid) {
    set<int> U;
    auto push = [&](int x) {
      U.insert(x);
      if (U.size() > 3) U.erase(U.begin());
    };

    int N = grid.size(), M = grid[0].size();
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      push(grid[i][j]);
      for (int l = 1;; ++l) {
        int ib = i - l, jb = j - l, iu = i + l, ju = j + l;
        if (ib < 0 || jb < 0 || iu >= N || ju >= M) break;

        // add all diagonal sides
        int sum = 0;
        for (int k = 0; k < l; ++k) {
          sum += grid[ib + k][j + k];
          sum += grid[i + k][ju - k];
          sum += grid[iu - k][j - k];
          sum += grid[i - k][jb + k];
        }
        push(sum);
      }
    }

    vector<int> ans(U.begin(), U.end());
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
