class Solution {
public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int N = grid.size(); vector<int> U{0, N * N + 1}, res(2);
    for (auto& row : grid) for (int x : row) U.push_back(x);
    sort(U.begin(), U.end());

    for (int i = 1; i < N * N + 2; ++i) {
      if (U[i] == U[i - 1]) res[0] = U[i];
      if (U[i] - U[i - 1] > 1) res[1] = U[i - 1] + 1;
    }
    return res;
  }
};
  