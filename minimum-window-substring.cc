class Solution {
public:
  string minWindow(string s, string t) {
    int st[128]{}, tt[128]{};
    for (char c : t) tt[c]++;

    auto check = [&]() {
      for (int i = 0; i < 128; ++i) {
        if (st[i] < tt[i]) return false;
      }
      return true;
    };

    int N = s.size(), r = 0, sl = -1, sr = N;
    for (int l = 0; l < N; ++l) {
      while (r < N && !check()) ++st[s[r++]];
      if (check() && r - l < sr - sl) {
        sl = l;
        sr = r;
      }
      --st[s[l]];
    }

    if (sl == -1) return "";
    return s.substr(sl, sr - sl);
  }
};
