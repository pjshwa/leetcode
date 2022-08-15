class Solution {
  int d[4][1 << 15], n, side;
  vector<int> matchsticks;

  bool r(int f, int state) {
    if (f == 4) return true;
    if (d[f][state] != -1) return d[f][state];

    int pre = 0;
    for (int i = 0; i < n; i++) {
      if (state & (1 << i)) pre += matchsticks[i];
    }

    bool ret = false;
    for (int i = 0; i < n; i++) {
      if (state & (1 << i)) continue;
      bool forms = pre + matchsticks[i] == (f + 1) * side;
      ret |= r(f + forms, state | (1 << i));
    }

    return d[f][state] = ret;
  }

public:
  bool makesquare(vector<int>& matchsticks) {
    int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    if (sum % 4) return false;

    n = matchsticks.size();
    side = sum / 4;
    this->matchsticks = matchsticks;

    memset(d, -1, sizeof(d));
    return r(0, 0);
  }
};
