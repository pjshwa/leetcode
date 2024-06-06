class Solution {
public:
  bool isNStraightHand(vector<int>& hand, int groupSize) {
    map<int, int> xt; set<int> xs;
    for (int e : hand) ++xt[e], xs.insert(e);
    for (int x : xs) {
      int f = xt[x];
      if (f == 0) continue;
      for (int i = x; i < x + groupSize; ++i) {
        xt[i] -= f;
        if (xt[i] < 0) return false;
      }
    }
    return true;
  }
};
