class Solution {
public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    int r = 0, ans = 0, cnt = 0;
    int t[256] = {0};
    for (int l = 0; l < s.size(); ++l) {
      while (r < s.size() && (cnt < k || t[s[r] - 'a'] > 0)) {
        if (t[s[r]]++ == 0) ++cnt;
        ++r;
      }
      ans = max(ans, r - l);
      if (--t[s[l]] == 0) --cnt;
    }
    return ans;
  }
};
