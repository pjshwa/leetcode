const int MAXN = 2e4;

class Solution {
  map<string, int> fi; int fcount = 0;
  string fi_inv[MAXN];
  vector<int> adj[MAXN];
  int indegree[MAXN], vis[MAXN];

  int fidx(string f) {
    auto found = fi.find(f);
    if (fi.end() == found) {
      fi.insert({f, fcount});
      fi_inv[fcount] = f;
      return fcount++;
    }
    else return found->second;
  }

public:
  vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    int N = ingredients.size();
    for (int i = 0; i < N; ++i) {
      int t = fidx(recipes[i]);
      for (auto& g : ingredients[i]) {
        int u = fidx(g);
        adj[u].push_back(t); ++indegree[t];
      }
    }

    queue<int> Q;
    for (auto& s : supplies) Q.push(fidx(s));
    while (!Q.empty()) {
      int u = Q.front(); Q.pop();
      vis[u] = 1;
      for (int v : adj[u]) {
        if (--indegree[v] == 0) Q.push(v);
      }
    }

    vector<string> ans;
    for (int i = 0; i < N; ++i) {
      int t = fidx(recipes[i]);
      if (vis[t]) ans.push_back(recipes[i]);
    }
    return ans;
  }
};
