class Solution {
public:
  int maximumRequests(int n, vector<vector<int>>& requests) {
    int Z = requests.size(), ans = 0;
    for (int s = 0; s < (1 << Z); s++) {
      int deg[n];
      for (int i = 0; i < n; i++) deg[i] = 0;
      for (int i = 0; i < Z; i++) {
        if (!(s & (1 << i))) continue;
        int u = requests[i][0], v = requests[i][1];
        deg[u]--, deg[v]++;
      }

      bool ok = true;
      for (int i = 0; i < n; i++) ok &= deg[i] == 0;
      if (ok) ans = max(ans, __builtin_popcount(s));
    }
    return ans;
  }
};
