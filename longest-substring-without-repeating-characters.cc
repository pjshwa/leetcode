class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    map<int, int> t;
    int n = s.size(), ep = -1, ans = 0;
    for (int sp = 0; sp < n; sp++) {
      while (ep < n - 1 && t[s[ep + 1]] == 0) t[s[++ep]]++;
      ans = max(ans, ep - sp + 1);
      t[s[sp]]--;
    }
    return ans;
  }
};
