const int INF = 0x3f3f3f3f;

class Solution {
public:
  int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    int n = edges.size();

    vector<int> adj[n];
    for (int i = 0; i < n; i++) {
      if (edges[i] == -1) continue;
      adj[i].push_back(edges[i]);
    }

    int cdist1[n], cdist2[n];
    auto bfs = [&](int node, int cdist[]) {
      fill(cdist, cdist + n, INF);
      queue<int> q;
      q.push(node);
      cdist[node] = 0;
      while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
          if (cdist[v] > cdist[u] + 1) cdist[v] = cdist[u] + 1, q.push(v);
        }
      }
    };

    bfs(node1, cdist1);
    bfs(node2, cdist2);

    int mdist = INF, mnode = -1;
    for (int i = 0; i < n; i++) {
      if (cdist1[i] == INF || cdist2[i] == INF) continue;
      if (max(cdist1[i], cdist2[i]) < mdist) {
        mdist = max(cdist1[i], cdist2[i]);
        mnode = i;
      }
    }
    return mnode;
  }
};
