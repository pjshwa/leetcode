class Solution {
public:
  bool detectCapitalUse(string word) {
    int n = word.size();
    int u = 0, l = 0;
    for (char c : word) {
      if (c >= 'A' && c <= 'Z') u++;
      else l++;
    }

    if (u == n || l == n) return true;
    if ('A' <= word[0] && word[0] <= 'Z') return l == n - 1;
    return false;
  }
};
