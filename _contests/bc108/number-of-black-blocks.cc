const int dx[4] = {-1, -1, 0, 0}, dy[4] = {-1, 0, -1, 0};

class Solution {
public:
  vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
    vector<long long> ans(5);

    set<pair<int, int>> B;
    for (auto C : coordinates) {
      int x = C[0], y = C[1];
      B.insert({x, y});
    }

    map<pair<int, int>, int> U;
    for (auto [x, y] : B) {
      for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx < 0 || nx >= m - 1 || ny < 0 || ny >= n - 1) continue;
        U[{nx, ny}]++;
      }
    }

    long long rem = (long long)(m - 1) * (n - 1);
    for (auto [p, cnt] : U) {
      ans[cnt] += 1;
      rem -= 1;
    }
    ans[0] = rem;
    return ans;
  }
};
