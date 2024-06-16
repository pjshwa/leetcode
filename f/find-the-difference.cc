class Solution {
public:
  char findTheDifference(string s, string t) {
    int u[26]{};
    for (char& c : t) u[c - 'a']++;
    for (char& c : s) u[c - 'a']--;
    for (int i = 0; i < 26; i++) if (u[i]) return 'a' + i;
    return 'a';
  }
};
