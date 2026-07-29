class Solution {
public:
  string smallestPalindrome(string s) {
    int C[26]{};
    for (char c : s) ++C[c - 'a'];

    string p = ""; int m = -1;
    for (int i = 0; i < 26; ++i) {
      if (C[i] & 1) m = i;
      for (int j = 0; j < C[i] / 2; ++j) p += (char)(i + 'a');
    }

    string ans = p;
    if (m != -1) ans += (char)(m + 'a');
    while (!p.empty()) ans += p.back(), p.pop_back();
    return ans;
  }
};
