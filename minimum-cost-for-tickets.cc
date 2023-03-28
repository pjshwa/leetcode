class Solution {
public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    int n = days.size();
    int c01 = costs[0], c07 = costs[1], c30 = costs[2];

    int d[n + 1]; memset(d, 0x3f, sizeof(d));
    d[0] = 0;
    for (int i = 1; i <= n; i++) {
      bool z01 = true, z07 = true, z30 = true;
      for (int j = i - 1; j >= 0; j--) {
        if (z01) d[i] = min(d[i], d[j] + c01);
        if (z07) d[i] = min(d[i], d[j] + c07);
        if (z30) d[i] = min(d[i], d[j] + c30);

        if (j == 0) break;
        if (days[i - 1] - days[j - 1] >= 1) z01 = false;
        if (days[i - 1] - days[j - 1] >= 7) z07 = false;
        if (days[i - 1] - days[j - 1] >= 30) z30 = false;
      }
    }

    return d[n];
  }
};
