class Solution {
public:
  int numberOfSpecialChars(string word) {
    int C[52]{}, ans = 0;
    for (auto c : word) {
      if (c >= 'a') ++C[c - 'a'];
      else ++C[c - 'A' + 26];
    }
    for (int i = 0; i < 26; ++i) ans += (C[i] && C[i + 26]);
    return ans;
  }
};
