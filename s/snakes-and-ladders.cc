const int INF = 0x3f3f3f3f;
using pii = pair<int, int>;

class Solution {
public:
  int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();

    function<pii(int)> get = [&](int x) {
      int r = (x - 1) / n;
      int c = (x - 1) % n;
      if (r % 2 == 1) c = n - 1 - c;
      return pii(n - 1 - r, c);
    };

    int cdist[n * n + 1];
    fill(cdist, cdist + n * n + 1, INF);

    queue<int> q;
    q.push(1);
    cdist[1] = 0;

    while (!q.empty()) {
      int v = q.front(); q.pop();

      for (int i = 1; i <= 6; i++) {
        int u = v + i;
        if (u > n * n) break;

        auto [pi, pj] = get(u);
        if (board[pi][pj] != -1) u = board[pi][pj];

        if (cdist[u] > cdist[v] + 1) {
          cdist[u] = cdist[v] + 1;
          q.push(u);
        }
      }
    }

    return cdist[n * n] == INF ? -1 : cdist[n * n];
  }
};
