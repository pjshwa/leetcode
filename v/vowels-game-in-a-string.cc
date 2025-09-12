class Solution {
  bool is_vowel(char c) {
    string vowels = "aeiou";
    for (char t : vowels) {
      if (c == t) return true;
    }
    return false;
  }

public:
  bool doesAliceWin(string s) {
    for (char c : s) {
      if (is_vowel(c)) return true;
    }
    return false;
  }
};
