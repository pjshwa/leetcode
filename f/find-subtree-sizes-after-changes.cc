class Solution {
public:
  vector<int> findSubtreeSizes(vector<int>& parent, string s) {
    int N = parent.size();
    vector<int> adj[N], C(26, -1), npar(N, -1), S(N);
    for (int i = 1; i < N; ++i) adj[parent[i]].push_back(i);

    function<void(int)> dfs = [&](int v) {
      int c = s[v] - 'a', prev = C[c];
      npar[v] = prev == -1 ? parent[v] : prev;
      C[c] = v; S[v] = 1;
      for (int u : adj[v]) dfs(u), S[v] += S[u];
      C[c] = prev;
    };
    dfs(0);

    for (int i = 0; i < N; ++i) adj[i].clear();
    for (int i = 0; i < N; ++i) if (npar[i] != -1) adj[npar[i]].push_back(i);
    dfs(0);
    return S;
  }
};
