using pii = pair<int, int>;

class Solution {
public:
  int minJumps(vector<int>& arr) {
    map<int, vector<int>> by_val;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
      by_val[arr[i]].push_back(i);
    }

    vector<vector<pii>> adj(2 * n);
    for (int i = 0; i < n - 1; i++) {
      adj[i].push_back({i + 1, 1});
      adj[i + 1].push_back({i, 1});
    }

    // Create virtual node to connect all nodes with same value.
    int it = n;
    for (auto& [_, vv] : by_val) {
      for (int v : vv) {
        adj[it].push_back({v, 0});
        adj[v].push_back({it, 1});
      }
      it++;
    }

    int cdist[2 * n];
    memset(cdist, 0x3f, sizeof(cdist));

    deque<pii> q;
    q.push_back({0, 0}); cdist[0] = 0;

    while (!q.empty()) {
      auto [u, d] = q.front(); q.pop_front();

      if (cdist[u] < d) continue;
      for (auto [v, w] : adj[u]) {
        if (cdist[v] > d + w) {
          if (w == 0) q.push_front({v, d}), cdist[v] = d;
          else q.push_back({v, d + w}), cdist[v] = d + w;
        }
      }
    }

    return cdist[n - 1];
  }
};
