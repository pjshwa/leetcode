const int MOD = 1e9 + 7;

class Solution {
  int d[100][201];
  vector<int> locations; int finish, N;

  int r(int i, int f) {
    if (d[i][f] != -1) return d[i][f];

    int ret = i == finish;
    for (int j = 0; j < N; ++j) {
      if (i == j) continue;
      int dist = abs(locations[i] - locations[j]);
      if (dist <= f) ret = (ret + r(j, f - dist)) % MOD;
    }
    return d[i][f] = ret;
  }

public:
  int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    N = locations.size(); this->locations = locations; this->finish = finish;
    memset(d, -1, sizeof(d));
    return r(start, fuel);
  }
};
