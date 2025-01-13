class Solution {
public:
  int minimumLength(string s) {
    int C[26]{}, ans = 0;
    for (char c : s) ++C[c - 'a'];
    for (int c = 0; c < 26; ++c) {
      if (C[c] == 0) continue;
      ans += 2 - (C[c] & 1);
    }
    return ans;
  }
};
