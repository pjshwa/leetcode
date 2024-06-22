class Solution {
public:
  int numberOfSpecialSubstrings(string s) {
    map<int, int> t; int ans = 0, r = 0, N = s.size();
    for (int l = 0; l < N; ++l) {
      while (r < N && t[s[r]] < 1) ++t[s[r++]];
      ans += r - l;
      --t[s[l]];
    }
    return ans;
  }
};
