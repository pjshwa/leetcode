class Solution {
public:
  long long numberOfSubstrings(string s) {
    int t[26]{}; long long ans = 0;
    for (char c : s) {
      int ci = c - 'a';
      ++t[ci];
      ans += t[ci];
    }
    return ans;
  }
};
