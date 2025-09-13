class Solution {
  bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

public:
  int maxFreqSum(string s) {
    int C[26]{};
    for (char c : s) ++C[c - 'a'];

    int f1 = 0, f2 = 0;
    for (int i = 0; i < 26; ++i) {
      if (is_vowel(i + 'a')) f1 = max(f1, C[i]);
      else f2 = max(f2, C[i]);
    }
    return f1 + f2;
  }
};
