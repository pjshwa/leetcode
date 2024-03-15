class Solution {
public:
  bool makePalindrome(string S) {
    int N = S.size(), cnt = 0;
    for (int s = 0;; ++s) {
      int e = N - 1 - s;
      if (s >= e) break;

      cnt += S[s] != S[e];
      if (cnt > 2) return false;
    }
    return true;
  }
};
