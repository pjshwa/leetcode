const int MAXN = 1e5;

class Solution {
  vector<int> cdist; queue<int> q;
  void bfs(vector<vector<int>>& adj) {
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int v : adj[u]) {
        if (cdist[v] == -1) cdist[v] = cdist[u] + 1, q.push(v);
      }
    }
  }

public:
  int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
    int N = edges1.size() + 1, M = edges2.size() + 1, cond = 1;
    vector<vector<int>> adj1(N, vector<int>()), adj2(M, vector<int>());
    for (auto& e : edges1) {
      adj1[e[0]].push_back(e[1]);
      adj1[e[1]].push_back(e[0]);
    }
    for (auto& e : edges2) {
      adj2[e[0]].push_back(e[1]);
      adj2[e[1]].push_back(e[0]);
    }

    cdist.assign(N, -1); cdist[0] = 0; q.push(0); bfs(adj1);
    int maxv1 = -1, maxd1 = -1;
    for (int i = 0; i < N; ++i) {
      if (cdist[i] > maxd1) maxd1 = cdist[i], maxv1 = i;
    }
    cdist.assign(N, -1); cdist[maxv1] = 0; q.push(maxv1); bfs(adj1);
    maxd1 = -1;
    for (int i = 0; i < N; ++i) {
      if (cdist[i] > maxd1) maxd1 = cdist[i];
    }
    cond += (maxd1 + 1) / 2;

    cdist.assign(M, -1); cdist[0] = 0; q.push(0); bfs(adj2);
    int maxv2 = -1, maxd2 = -1;
    for (int i = 0; i < M; ++i) {
      if (cdist[i] > maxd2) maxd2 = cdist[i], maxv2 = i;
    }
    cdist.assign(M, -1); cdist[maxv2] = 0; q.push(maxv2); bfs(adj2);
    maxd2 = -1;
    for (int i = 0; i < M; ++i) {
      if (cdist[i] > maxd2) maxd2 = cdist[i];
    }
    cond += (maxd2 + 1) / 2;

    return max({cond, maxd1, maxd2});
  }
};
