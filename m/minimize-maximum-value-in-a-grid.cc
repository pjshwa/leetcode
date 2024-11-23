using pii = pair<int, int>;

class Solution {
public:
  vector<vector<int>> minScore(vector<vector<int>>& grid) {
    int N = grid.size(), M = grid[0].size();

    using T = pair<int, pii>;
    priority_queue<T, vector<T>, greater<T>> pq;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) pq.push({grid[i][j], {i, j}});

    vector<int> Rmax(N, 0), Cmax(M, 0);
    vector<vector<int>> res(N, vector<int>(M, 0));

    while (!pq.empty()) {
      auto [i, j] = pq.top().second; pq.pop();
      res[i][j] = max(Rmax[i], Cmax[j]) + 1;
      Rmax[i] = Cmax[j] = res[i][j];
    }

    return res;
  }
};
