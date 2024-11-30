using ll = long long;
const int MAXN = 1e9;

class Solution {
  unordered_map<int, vector<int>> adj;
  unordered_map<ll, int> E;
  unordered_map<int, int> indeg, outdeg;
  vector<int> traj;

  ll key(int u, int v) {
    return (ll)u * (MAXN + 1) + v;
  }

  void dfs(int v) {
    while (!adj[v].empty()) {
      int u = adj[v].back(); adj[v].pop_back();
      ll k = key(v, u);
      if (E.count(k) && E[k] > 0) {
        --E[k]; dfs(u);
      }
    }
    traj.push_back(v);
  }

public:
  vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
    for (auto& pair : pairs) {
      int u = pair[0], v = pair[1];
      adj[u].push_back(v); ++E[key(u, v)];
      ++outdeg[u]; ++indeg[v];
    }

    int start = pairs[0][0];
    for (auto& pair : pairs) {
      if (indeg[pair[0]] + 1 == outdeg[pair[0]]) {
        start = pair[0];
        break;
      }
    }

    dfs(start);
    reverse(traj.begin(), traj.end());
    int Z = traj.size(), last = start;
    vector<vector<int>> ans;
    for (int i = 1; i < Z; ++i) {
      int v = traj[i];
      ans.emplace_back(vector<int>{last, v});
      last = v;
    }
    return ans;
  }
};
