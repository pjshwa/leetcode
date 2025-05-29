const int MAXN = 1e5;
int O[MAXN], E[MAXN], S[MAXN];

class Solution {
  vector<vector<int>> adj1, adj2;

  void dfs_s(int v, int p, vector<vector<int>>& adj) {
    E[v] = 1;
    for (int u : adj[v]) {
      if (u == p) continue;
      dfs_s(u, v, adj);
      E[v] += O[u]; O[v] += E[u];
    }
  }

  void dfs_u(int v, int p, int l, vector<vector<int>>& adj) {
    S[v] = l ? O[0] : E[0];
    for (int u : adj[v]) {
      if (u == p) continue;
      dfs_u(u, v, 1 - l, adj);
    }
  }

  void init_p() {
    memset(O, 0, sizeof(O));
    memset(E, 0, sizeof(E));
  }

public:
  vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
    int N = edges1.size() + 1, M = edges2.size() + 1;
    adj1.resize(N); adj2.resize(M);
    for (auto& e : edges1) adj1[e[0]].push_back(e[1]), adj1[e[1]].push_back(e[0]);
    for (auto& e : edges2) adj2[e[0]].push_back(e[1]), adj2[e[1]].push_back(e[0]);

    init_p(); dfs_s(0, -1, adj2);
    int maxS = max(O[0], E[0]);
    init_p(); dfs_s(0, -1, adj1);
    dfs_u(0, -1, 0, adj1);

    vector<int> result;
    for (int i = 0; i < N; ++i) result.push_back(S[i] + maxS);
    return result;
  }
};
