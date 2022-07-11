class Solution {
  int on[1001], off[1001];
public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    memset(on, 0, sizeof(on));
    memset(off, 0, sizeof(off));

    for (auto& tr : trips) {
      int pn = tr[0], f = tr[1], t = tr[2];
      on[f] += pn;
      off[t] += pn;
    }

    int cur = 0;
    for (int i = 0; i <= 1000; i++) {
      cur -= off[i];
      cur += on[i];
      if (cur > capacity) return false;
    }

    return true;
  }
};
