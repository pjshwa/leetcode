using ll = long long;
using pii = pair<int, int>;

const int MAX = 1e5;
const ll INF = 1e18;

class Solution {
  ll d1[MAX + 1], d2[MAX + 1];
  vector<int> graph[MAX + 1];
public:
  int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    int n = edges.size();
    for (int i = 0; i < n; i++) {
      if (edges[i] == -1) continue;
      graph[i].push_back(edges[i]);
    }

    fill(d1, d1 + MAX + 1, INF);
    fill(d2, d2 + MAX + 1, INF);    

    queue<pii> q;

    q.push({node1, 0});
    d1[node1] = 0;
    while (!q.empty()) {
      auto [v, c] = q.front(); q.pop();

      for (auto &u : graph[v]) {
        if (d1[u] > c + 1) {
          d1[u] = c + 1;
          q.push({u, d1[u]});
        }
      }
    }

    q.push({node2, 0});
    d2[node2] = 0;
    while (!q.empty()) {
      auto [v, c] = q.front(); q.pop();

      for (auto &u : graph[v]) {
        if (d2[u] > c + 1) {
          d2[u] = c + 1;
          q.push({u, d2[u]});
        }
      }
    }

    ll mval = INF, mi = -1;
    for (int i = 0; i < n; i++) {
      if (d1[i] == INF || d2[i] == INF) continue;
      ll cur = max(d1[i], d2[i]);
      if (cur < mval) {
        mval = cur;
        mi = i;
      }
    }

    return mi;
  }
};
