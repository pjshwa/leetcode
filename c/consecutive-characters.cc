class Solution {
public:
  int maxPower(string s) {
    int streak = 0, mstreak = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (i == 0 || s[i] != s[i - 1]) {
        streak = 1;
      } else {
        ++streak;
      }
      mstreak = max(mstreak, streak);
    }

    return mstreak;
  }
};
