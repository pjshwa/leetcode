class Solution {
public:
  string repeatLimitedString(string s, int repeatLimit) {
    int C[26]{};
    for (char c : s) ++C[c - 'a'];

    string ans = ""; int str = 0, last = -1;
    while (1) {
      int ok = 0;
      for (int i = 25; i >= 0; --i) {
        if (C[i] == 0) continue;
        if (str == repeatLimit && last == i) continue;

        if (last == i) str += 1;
        else str = 1;
        ans += 'a' + i; --C[i];
        last = i; ok = 1;
        break;
      }
      if (!ok) break;
    }

    return ans;
  }
};
