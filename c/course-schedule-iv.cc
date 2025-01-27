class Solution {
public:
  vector<bool> checkIfPrerequisite(int N, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    vector<int> adj[N];
    for (auto& p : prerequisites) adj[p[0]].push_back(p[1]);

    vector<vector<int>> cdist(N, vector<int>(N, -1));
    queue<int> q;
    for (int s = 0; s < N; ++s) {
      q.push(s); cdist[s][s] = 0;
      while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
          if (cdist[s][v] == -1) {
            cdist[s][v] = cdist[s][u] + 1;
            q.push(v);
          }
        }
      }
    }

    vector<bool> res;
    for (auto& q : queries) res.push_back(cdist[q[0]][q[1]] != -1);
    return res;
  }
};
