const int INF = 0x3f3f3f3f;

class Solution {
public:
  int paintWalls(vector<int>& cost, vector<int>& time) {
    int N = cost.size();

    vector<int> d(N + 1, INF); d[0] = 0;
    for (int i = 0; i < N; ++i) {
      for (int nt = N; nt >= 0; --nt) {
        int pt = max(0, nt - time[i] - 1);
        d[nt] = min(d[nt], d[pt] + cost[i]);
      }
    }

    return d[N];
  }
};
