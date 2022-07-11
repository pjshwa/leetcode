class Solution {
public:
  bool isSubsequence(string s, string t) {
    int j = 0, n = s.size();
    for (char c : t) {
      if (j < n && c == s[j]) j++;
    }
    return j == n;
  }
};
