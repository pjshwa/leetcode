class Solution {
public:
  double new21Game(int n, int k, int maxPts) {
    if (k == 0) return 1;

    double P[n + 1];
    memset(P, 0, sizeof(P)); P[0] = 1;

    for (int i = 1; i <= n; i++) {
      P[i] = P[i - 1];
      int s = max(0, i - maxPts), e = min(i - 1, k - 1);
      if (s > e) continue;

      double c = P[e];
      if (s > 0) c -= P[s - 1];
      c /= maxPts;
      P[i] += c;
    }

    return P[n] - P[k - 1];
  }
};
