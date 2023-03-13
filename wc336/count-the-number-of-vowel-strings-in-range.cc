class Solution {
  bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

public:
  int vowelStrings(vector<string>& words, int left, int right) {
    int ans = 0;
    for (int i = left; i <= right; i++) {
      if (is_vowel(words[i][0]) && is_vowel(words[i][words[i].size() - 1])) {
        ans++;
      }
    }
    return ans;
  }
};
