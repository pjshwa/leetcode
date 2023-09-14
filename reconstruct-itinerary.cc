const int MAX = 600;

class Solution {
  map<string, int> cache;
  map<int, string> cache_inv;
  int cache_it = 0;

  int sidx(string s) {
    if (cache.count(s)) return cache[s];

    cache[s] = cache_it;
    cache_inv[cache_it] = s;
    return cache_it++;
  }

  vector<int> adj[MAX];
  int E[MAX][MAX];
  vector<int> traj;

  void dfs(int v) {
    for (int u : adj[v]) {
      if (E[v][u] == 0) continue;
      --E[v][u]; dfs(u);
    }
    traj.push_back(v);
  }

public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    memset(E, 0, sizeof E);

    set<string> names;
    for (auto& ticket : tickets) {
      names.insert(ticket[0]);
      names.insert(ticket[1]);
    }

    int S;
    for (auto& name : names) {
      int si = sidx(name);
      if (name == "JFK") S = si;
    }

    for (auto& ticket : tickets) {
      int u = sidx(ticket[0]), v = sidx(ticket[1]);
      adj[u].push_back(v); ++E[u][v];
    }
    for (int i = 0; i < MAX; ++i) sort(adj[i].begin(), adj[i].end());
    dfs(S);

    vector<string> ans;
    for (int e : traj) ans.push_back(cache_inv[e]);
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
