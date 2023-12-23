class Solution {
public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    int C[256] = {0}, N = s.size();

    int ans = 0, cnt = 0;
    for (int l = 0, r = 0; l < N; ++l) {
      while (r < N && (cnt < 2 || C[s[r]])) {
        if (C[s[r]]++ == 0) ++cnt;
        ++r;
      }
      ans = max(ans, r - l);
      if (--C[s[l]] == 0) --cnt;
    }
    return ans;
  }
};
