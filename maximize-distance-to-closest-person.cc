const int MAX = 2e4, INF = 1e9 + 7;

class Solution {
  int ldist[MAX + 1], rdist[MAX + 1];
public:
  int maxDistToClosest(vector<int>& seats) {
    fill(ldist, ldist + MAX + 1, INF);
    fill(rdist, rdist + MAX + 1, INF);

    int n = seats.size();
    for (int i = 0; i < n; i++) {
      if (seats[i]) ldist[i] = 0;
      else {
        if (i > 0 && ldist[i - 1] < INF) ldist[i] = ldist[i - 1] + 1;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (seats[i]) rdist[i] = 0;
      else {
        if (i < n - 1 && rdist[i + 1] < INF) rdist[i] = rdist[i + 1] + 1;
      }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) if (!seats[i]) ans = max(ans, min(ldist[i], rdist[i]));
    return ans;
  }
};
