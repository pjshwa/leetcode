class Solution {
  int d[1005];

public:
  int paintWalls(vector<int>& cost, vector<int>& time) {
    int N = cost.size();

    memset(d, 0x3f, sizeof(d)); d[N] = 0;
    for (int i = 0; i < N; i++) {
      int C = cost[i], T = time[i];
      for (int pT = 0; pT <= N; pT++) {
        int nT = max(0, pT - T - 1);
        d[nT] = min(d[nT], d[pT] + C);
      }
    }

    return d[0];
  }
};
