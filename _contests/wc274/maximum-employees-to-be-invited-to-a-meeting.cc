class Solution {

vector<int> graph[100001], rgraph[100001];

// 0: Not visited
// 1: Visited
// 2: Part of cycle
int vis[100001];
bool vis2[100001];
bool vis3[100001];
int cycnt[100001];
int curcnt;

void dfs(int node) {
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
  curcnt++;
  int dst = graph[node][0];
  if (!vis2[dst]) dfs2(dst);
}

void dfs3(int node) {
  vis3[node] = true;
  cycnt[node] = curcnt;
  int dst = graph[node][0];
  if (!vis3[dst]) dfs3(dst);
}

int dfs4(int node, int cdepth) {
  vis3[node] = true;
  int ret = cdepth;
  for (int dst : rgraph[node]) {
    if (vis[dst] != 2 && !vis3[dst]) ret = max(ret, dfs4(dst, cdepth + 1));
  }
  return ret;
}

public:
  int maximumInvitations(vector<int>& favorite) {
    int n = favorite.size();
    for (int i = 0; i < n; i++) {
      graph[i].push_back(favorite[i]);
      rgraph[favorite[i]].push_back(i);
    }

    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
      if (!vis[i]) dfs(i);
    }

    memset(vis2, 0, sizeof(vis2));
    memset(vis3, 0, sizeof(vis3));
    for (int i = 0; i < n; i++) {
      if (!vis2[i] && vis[i] == 2) {
        curcnt = 0;
        dfs2(i);
        dfs3(i);
      }
    }
      
    memset(vis3, 0, sizeof(vis3));

    int ans = 0;
    vector<int> cy2cnt;
    for (int i = 0; i < n; i++) {
      if (vis[i] == 2) {
        if (cycnt[i] >= 3) ans = max(ans, cycnt[i]);
        else if (!vis3[i]) {
          int other = graph[i][0];
          int ext = dfs4(other, 0) + dfs4(i, 0);
          cy2cnt.push_back(ext + 2);
        }
      }
    }

    int cy2all = accumulate(cy2cnt.begin(), cy2cnt.end(), 0);
    return max(ans, cy2all);
  }
};
