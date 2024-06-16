using pii = pair<int, int>;

class Solution {
public:
  int treeDiameter(vector<vector<int>>& edges) {
    int N = edges.size() + 1;
    vector<int> adj[N];
    for (auto& e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    auto maxd = [&](int s) {
      queue<int> q; vector<int> cdist(N, -1);
      q.push(s); cdist[s] = 0;
      while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) if (cdist[v] == -1) {
          cdist[v] = cdist[u] + 1;
          q.push(v);
        }
      }

      int maxv = *max_element(cdist.begin(), cdist.end());
      for (int i = 0; i < N; ++i) {
        if (cdist[i] == maxv) return pii(i, maxv);
      }
      return pii(-1, -1);
    };

    auto [ov, od] = maxd(0);
    auto [ev, ed] = maxd(ov);
    return ed;
  }
};
