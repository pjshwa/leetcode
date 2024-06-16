using ll = long long;
using pll = pair<ll, ll>;

class Solution {
public:
  long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    int n = roads.size() + 1;
    vector<int> adj[n];
    for (auto& r : roads) {
      adj[r[0]].push_back(r[1]);
      adj[r[1]].push_back(r[0]);
    }

    function<pll(ll, ll)> dfs = [&](int u, int p) {
      ll size = 1, fuel = 0;
      for (int v : adj[u]) {
        if (v == p) continue;

        auto [z, f] = dfs(v, u);
        fuel += f + (z - 1) / seats + 1;
        size += z;
      }
      return pll(size, fuel);
    };

    return dfs(0, -1).second;
  }
};
