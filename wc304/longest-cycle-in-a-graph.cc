class Solution {
  vector<int> graph[100001];
  int vis[100001], vis2[100001];
  int cc;

  void dfs(int node) {
    if (graph[node].size() == 0) return vis[node] = 1, void();

    int dst = graph[node][0];
    if (node == dst) vis[node] = 2;
    else {
      vis[node] = -1;

      // Cycle is detected
      if (vis[dst] == -1) {
        vis[dst] = 2;
        int s = graph[dst][0];
        while (s != dst) {
          vis[s] = 2;
          s = graph[s][0];
        }
      }
      else {
        if (!vis[dst]) dfs(dst);
        if (vis[node] != 2) vis[node] = 1;
      }
    }
  }

  void dfs2(int node) {
    vis2[node] = true;
    cc++;
    for (int i = 0; i < graph[node].size(); i++) {
      int dst = graph[node][i];
      if (vis[dst] == 2 && !vis2[dst]) dfs2(dst);
    }

  }

public:
  int longestCycle(vector<int>& edges) {
    int n = edges.size();
    for (int i = 0; i < n; i++) {
      if (edges[i] == -1) continue;
      graph[i].push_back(edges[i]);
    }

    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
      if (!vis[i]) dfs(i);
    }

    memset(vis2, 0, sizeof(vis2));
    int ans = -1;
    for (int i = 0; i < n; i++) {
      if (vis[i] == 2 && !vis2[i]) {
        cc = 0;
        dfs2(i);
        ans = max(ans, cc);
      }
    }

    return ans;
      
  }
};
