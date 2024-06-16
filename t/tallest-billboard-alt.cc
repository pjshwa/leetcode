class Solution {
public:
  int tallestBillboard(vector<int>& rods) {
    map<int, int> d; d[0] = 0;
    for (int rod : rods) {
      auto nd = d;

      for (auto& [dif, t] : d) {
        int s = t - dif;
        nd[dif + rod] = max(nd[dif + rod], t + rod);
        nd[abs(dif - rod)] = max(nd[abs(dif - rod)], max(s + rod, t));
      }

      d = nd;
    }
    return d[0];
  }
};
