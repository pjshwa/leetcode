class Solution {
public:
  int minimumScore(string s, string t) {
    int Sz = s.size(), Tz = t.size(), si;

    // how much of string s should be 'consumed' from the left for t[0..i] to be its subsequence?
    int LR[Tz]; si = 0;
    for (int ti = 0; ti < Tz; ++ti) {
      while (si < Sz && s[si] != t[ti]) ++si;
      LR[ti] = si;
      if (si < Sz) ++si;
    }

    // how much of string s should be 'consumed' from the right for t[i...Tz] to be its subsequence?
    int RR[Tz]; si = Sz - 1;
    for (int ti = Tz - 1; ti >= 0; --ti) {
      while (si >= 0 && s[si] != t[ti]) --si;
      RR[ti] = si;
      if (si >= 0) --si;
    }

    int ans = Tz;
    for (int ti = 0; ti < Tz; ++ti) {
      if (LR[ti] < Sz) ans = min(ans, Tz - ti - 1);
      if (RR[ti] >= 0) ans = min(ans, ti);
    }
    if (ans == 0) return 0;

    int tr = 0;
    for (int tl = 0; tl < Tz; ++tl) {
      while (tr < Tz && LR[tl] >= RR[tr]) ++tr;
      if (LR[tl] < Sz && tr < Tz) {
        ans = min(ans, tr - tl - 1);
      }
    }

    return ans;
  }
};
