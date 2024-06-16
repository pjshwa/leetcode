const int MAX_L = 1e5, BIAS_L = 5e4, MAX_S = 15, INF = 0x3f3f3f3f;

class Solution {

public:
  int racecar(int target) {
    int d[MAX_L + 1][MAX_S][2];
    memset(d, 0x3f, sizeof(d));

    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, 1); d[BIAS_L][0][1] = 0;

    while (!q.empty()) {
      auto [p, s, dir] = q.front(); q.pop();
      if (p == target) return d[p + BIAS_L][s][dir];

      {
        int spd = 1 << s; spd *= (dir == 1 ? 1 : -1);
        int npos = p + spd, ns = s + 1;
        if (npos >= -BIAS_L && npos <= BIAS_L && ns < MAX_S) {
          if (d[npos + BIAS_L][ns][dir] > d[p + BIAS_L][s][dir] + 1) {
            d[npos + BIAS_L][ns][dir] = d[p + BIAS_L][s][dir] + 1;
            q.emplace(npos, ns, dir);
          }
        }
      }
      {
        if (d[p + BIAS_L][0][1 - dir] > d[p + BIAS_L][s][dir] + 1) {
          d[p + BIAS_L][0][1 - dir] = d[p + BIAS_L][s][dir] + 1;
          q.emplace(p, 0, 1 - dir);
        }
      }
    }

    return -1;
  }
};
