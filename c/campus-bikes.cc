using tii = tuple<int, int, int>;

class Solution {
public:
  vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
    int N = workers.size(), M = bikes.size();

    priority_queue<tii, vector<tii>, greater<tii>> pq;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      int d = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
      pq.push({d, i, j});
    }

    vector<bool> w_used(N, false), b_used(M, false);
    vector<int> ans(N, -1);

    while (!pq.empty()) {
      auto [d, i, j] = pq.top(); pq.pop();
      if (w_used[i] || b_used[j]) continue;
      w_used[i] = b_used[j] = true;
      ans[i] = j;
    }

    return ans;
  }
};
