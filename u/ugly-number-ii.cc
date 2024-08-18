class Solution {
public:
  int nthUglyNumber(int n) {
    int vis[40][40][40] = {};

    using T = tuple<long long, int, int, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.emplace(1, 0, 0, 0); vis[0][0][0] = 1;

    for (int i = 1; i < n; ++i) {
      auto [x, a, b, c] = pq.top(); pq.pop();
      if (a + 1 <= 40 && !vis[a + 1][b][c]) {
        pq.emplace(x * 2, a + 1, b, c);
        vis[a + 1][b][c] = 1;
      }
      if (b + 1 <= 40 && !vis[a][b + 1][c]) {
        pq.emplace(x * 3, a, b + 1, c);
        vis[a][b + 1][c] = 1;
      }
      if (c + 1 <= 40 && !vis[a][b][c + 1]) {
        pq.emplace(x * 5, a, b, c + 1);
        vis[a][b][c + 1] = 1;
      }
    }
    return get<0>(pq.top());
  }
};
