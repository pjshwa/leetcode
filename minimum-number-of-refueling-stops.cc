using ll = long long;

const int MAX = 555;
const ll INF = 1e18;

class Solution {
  ll d[MAX + 1];
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int n = stations.size();

    d[0] = startFuel;
    for (int i = 1; i <= n; i++) for (int k = i; k >= 0; k--) {
      int dist = stations[i - 1][0], fuel = stations[i - 1][1];
      if (dist <= d[k]) d[k + 1] = max(d[k] + fuel, d[k + 1]);
    }

    for (int k = 0; k <= n; k++) {
      if (d[k] >= target) return k;
    }
    return -1;
  }
};
