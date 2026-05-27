class Solution {
public:
  int numberOfSpecialChars(string word) {
    int T[26]{}, ans = 0;
    for (auto c : word) {
      if (c >= 'a') {
        int t = c - 'a';
        if (T[t] == 0 || T[t] == 2) ++T[t];
      } else {
        int t = c - 'A';
        if (T[t] == 0) T[t] = 3;
        else if (T[t] == 1) T[t] = 2;
      }
    }
    for (int i = 0; i < 26; ++i) ans += (T[i] == 2);
    return ans;
  }
};
