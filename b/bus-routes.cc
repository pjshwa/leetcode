const int MAXR = 1e6, INF = 0x3f3f3f3f;
const int MAXV = MAXR + 500;
vector<pair<int, int>> adj[MAXV];
int cdist[MAXV];

class Solution {
public:
  int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
    vector<int> vertices{source, target};
    for (auto route : routes) {
      for (int st : route) vertices.push_back(st);
    }
    for (int v : vertices) {
      adj[v].clear();
      cdist[v] = INF;
    }

    int Z = routes.size();
    for (int i = 0; i < Z; i++) {
      int bus_st = MAXR + i;

      // initialize first
      adj[bus_st].clear();
      cdist[bus_st] = INF;

      // emulate going in and out of the bus
      for (int st : routes[i]) {
        adj[st].emplace_back(bus_st, 1);
        adj[bus_st].emplace_back(st, 0);
      }
    }

    // perform 0-1 bfs
    deque<int> dq;
    dq.push_back(source); cdist[source] = 0;

    while (dq.size()) {
      auto v = dq.front(); dq.pop_front();
      for (auto [u, d] : adj[v]) {
        if (d == 0) {
          if (cdist[u] > cdist[v]) {
            cdist[u] = cdist[v];
            dq.push_front(u);
          }
        }
        else {
          if (cdist[u] > cdist[v] + 1) {
            cdist[u] = cdist[v] + 1;
            dq.push_back(u);
          }
        }
      }
    }

    int ans = cdist[target];
    return ans == INF ? -1 : ans;
  }
};
