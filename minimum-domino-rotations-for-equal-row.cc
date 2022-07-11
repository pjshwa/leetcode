class Solution {
public:
  int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    int n = tops.size();
    map<int, int> t;
    for (int i = 0; i < n; i++) {
      t[tops[i]]++;
      t[bottoms[i]]++;
    }

    int u = -1;
    for (auto& [k, v] : t) {
      if (v >= n) {
        u = k;
        break;
      }
    }
    if (u == -1) return -1;

    int tto = 0, bto = 0;
    for (int i = 0; i < n; i++) {
      if (tops[i] != u && bottoms[i] != u) return -1;
      if (tops[i] == u && bottoms[i] == u) continue;
      if (tops[i] == u) tto++;
      else bto++;
    }

    return min(tto, bto);
  }
};
