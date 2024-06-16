class Solution {
public:
  int minimumLength(string s) {
    int N = s.size();
    int l = 0, r = N - 1;
    while (l < r) {
      if (s[l] != s[r]) break;

      char c = s[l];
      while (l < N && s[l] == c) l++;
      while (r >= 0 && s[r] == c) r--;
    }

    return max(0, r - l + 1);
  }
};
