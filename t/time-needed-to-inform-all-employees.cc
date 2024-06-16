const int MAX = 1e5;

class Solution {
  vector<int> adj[MAX], informTime;

  int dfs(int v) {
    int ret = 0;
    for (int u : adj[v]) {
      ret = max(ret, dfs(u));
    }
    ret += informTime[v];
    return ret;
  }

public:
  int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    this->informTime = informTime;
    for (int i = 0; i < n; ++i) {
      int m = manager[i];
      if (m != -1) adj[m].push_back(i);
    }
    return dfs(headID);
  }
};
