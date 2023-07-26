using ll = long long;
const int INF = 1e7 + 1;

class Solution {
public:
  int minSpeedOnTime(vector<int>& dist, double hour) {
    int N = dist.size();
    ll H = hour * 100 + 0.5;

    int l = 1, r = INF;
    while (l < r) {
      int m = (l + r) / 2;

      ll sum = 0;
      for (int i = 0; i < N - 1; i++) {
        sum += (dist[i] - 1) / m + 1;
      }

      if (100 * dist[N - 1] > m * (H - 100 * sum)) l = m + 1;
      else r = m;
    }

    return l == INF ? -1 : l;
  }
};
