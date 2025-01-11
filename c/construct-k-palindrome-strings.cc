class Solution {
public:
  bool canConstruct(string s, int k) {
    int C[26] = {}, N = s.size();
    for (char c : s) ++C[c - 'a'];

    int odd = 0;
    for (int i = 0; i < 26; ++i) {
      if (C[i] % 2) ++odd;
    }
    return odd <= k && k <= N;
  }
};
