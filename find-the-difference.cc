class Solution {
  int u[26];
public:
  char findTheDifference(string s, string t) {
    memset(u, 0, sizeof(u));
    for (char& c : t) u[c - 'a']++;
    for (char& c : s) u[c - 'a']--;
    for (int i = 0; i < 26; i++) {
      if (u[i]) return 'a' + i;
    }
    return 'a';
  }
};
