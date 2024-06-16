class Solution {
public:
  int appendCharacters(string s, string t) {
    int Z = t.size(), i = 0;
    for (char c : s) {
      if (i < Z && t[i] == c) ++i;
    }
    return Z - i;
  }
};
