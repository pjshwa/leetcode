class Solution {
  bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; 
  }

public:
  int maxVowels(string s, int k) {
    int ans = 0;
    for (int i = 0; i < k; i++) {
      if (is_vowel(s[i])) ans++;
    }

    int cnt = ans;
    for (int i = k; i < s.size(); i++) {
      if (is_vowel(s[i])) cnt++;
      if (is_vowel(s[i - k])) cnt--;
      ans = max(ans, cnt);
    }

    return ans;
  }
};
