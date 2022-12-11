using ll = long long;
using pll = pair<ll, ll>;
using tll = tuple<ll, ll, ll>;

const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
const ll INF = 1e18;

class Solution {
  ll cdist[1001][1001];
  int n, m;
  vector<vector<int>> grid;

  void dijk(int si, int sj) {
    for (int i = 0; i < n; i++) fill(cdist[i], cdist[i] + m, INF);

    priority_queue<tll, vector<tll>, greater<tll>> pq;
    pq.push({grid[si][sj], si, sj});
    cdist[si][sj] = grid[si][sj];

    while (!pq.empty()) {
      auto [w, ui, uj] = pq.top();
      pq.pop();

      if (w > cdist[ui][uj]) continue;

      for (int k = 0; k < 4; k++) {
        int vi = ui + dx[k], vj = uj + dy[k];
        if (vi < 0 || vi >= n || vj < 0 || vj >= m) continue;

        ll nw = max((ll)grid[vi][vj], w);
        if (nw < cdist[vi][vj]) {
          cdist[vi][vj] = nw;
          pq.push({nw, vi, vj});
        }
      }
    }
  }

public:
  vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
    n = grid.size(), m = grid[0].size();
    this->grid = grid;

    dijk(0, 0);

    map<ll, ll> P;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        P[cdist[i][j]]++;
      }
    }

    ll lval = 0;
    for (auto& [k, v] : P) {
      lval += v;
      P[k] = lval;
    }

    int Q = queries.size();
    vector<int> ans(Q);
    for (int i = 0; i < Q; i++) {
      int q = queries[i];
      auto it = P.upper_bound(q - 1);
      if (it == P.begin()) ans[i] = 0;
      else ans[i] = prev(it)->second;
    }

    return ans;
  }
};
