class Solution {
  vector<int> graph[10005];
  vector<int> pos;
  bool able = false;
  int cur;

  void dfs(int v, int d) {
    if (d == 3) {
      able = true;
      return;
    }
    if (able) return;

    for (int u : graph[v]) {
      if (cur & pos[u]) continue;
      cur ^= pos[u];
      dfs(u, d + 1);
      cur ^= pos[u];
    }

  }

public:
  bool makesquare(vector<int>& matchsticks) {
    int sum = 0, n = matchsticks.size();
    for (int i = 0; i < n; i++) sum += matchsticks[i];
    if (sum % 4) return false;

    int side = sum / 4;
    for (int i = 0; i < (1 << n); i++) {
      int cur = 0;
      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) cur += matchsticks[j];
      }
      if (cur == side) pos.push_back(i);
    }

    int psz = pos.size();
    for (int i = 0; i < psz; i++) for (int j = i + 1; j < psz; j++) {
      if (pos[i] & pos[j]) continue;
      graph[i].push_back(j);
      graph[j].push_back(i);
    }

    for (int i = 0; i < psz; i++) {
      cur = pos[i];
      dfs(i, 1);
    }
    return able;
  }

};
