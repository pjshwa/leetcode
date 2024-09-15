const int MAXN = 5e5;

class Solution {
  map<string, int> fi; int fcount = 0;
  string inv_fi[MAXN];

  int fidx(string f) {
    auto found = fi.find(f);
    if (fi.end() == found) {
      fi.insert({f, fcount});
      inv_fi[fcount] = f;
      return fcount++;
    }
    else return found->second;
  }

  vector<int> adj[MAXN];
  int level[MAXN], parent[MAXN], indegree[MAXN];

  void dfs(int v, int p, int l) {
    level[v] = l;
    for (int u : adj[v]) {
      if (u == p) continue;
      parent[u] = v;
      dfs(u, v, l + 1);
    }
  }

public:
  string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
    memset(indegree, 0, sizeof(indegree));
    for (auto& r : regions) {
      int p = fidx(r[0]);
      for (int i = 1; i < r.size(); ++i) {
        int c = fidx(r[i]);
        adj[p].push_back(c); ++indegree[c];
      }
    }

    int root;
    for (root = 0; root < fcount; ++root) {
      if (indegree[root] == 0) break;
    }
    dfs(root, -1, 0);

    int r1 = fidx(region1), r2 = fidx(region2);
    while (level[r1] > level[r2]) r1 = parent[r1];
    while (level[r2] > level[r1]) r2 = parent[r2];
    while (r1 != r2) r1 = parent[r1], r2 = parent[r2];
    return inv_fi[r1];
  }
};
