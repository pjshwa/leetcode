class Solution {
public:
  bool stoneGameIX(vector<int>& stones) {
    int N = stones.size(), OC[3]{};
    for (int e : stones) ++OC[e % 3];
    if (OC[0] == N) return false;

    int o = OC[0], l, C[3], t;
    C[1] = OC[1], C[2] = OC[2];
    for (l = 0; l < N; ++l) {
      int t = l > 0 && l % 2 == 0 ? 2 : 1;
      if (C[t] == 0) break;
      --C[t];
    }
    t = l + o;
    if (l > 0 && t < N && (t & 1)) return true;

    C[1] = OC[1], C[2] = OC[2];
    for (l = 0; l < N; ++l) {
      int t = l > 0 && l % 2 == 0 ? 1 : 2;
      if (C[t] == 0) break;
      --C[t];
    }
    t = l + o;
    if (l > 0 && t < N && (t & 1)) return true;

    return false;
  }
};
