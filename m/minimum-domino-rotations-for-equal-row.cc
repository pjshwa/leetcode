class Solution {
public:
  int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    int n = tops.size(), T[7] = {};
    for (int i = 0; i < n; ++i) ++T[tops[i]], ++T[bottoms[i]];

    int u;
    for (u = 1; u <= 6; ++u) if (T[u] >= n) break;
    if (u == 7) return -1;

    int tto = 0, bto = 0;
    for (int i = 0; i < n; ++i) {
      if (tops[i] != u && bottoms[i] != u) return -1;
      if (tops[i] == u && bottoms[i] == u) continue;
      tops[i] == u ? ++bto : ++tto;
    }
    return min(tto, bto);
  }
};
