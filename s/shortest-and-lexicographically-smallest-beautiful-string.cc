class Solution {
public:
  string shortestBeautifulSubstring(string s, int k) {
    int N = s.size(), r = 0, cnt = 0;
    int mlen = N + 1;
    for (int l = 0; l < N; ++l) {
      while (r < N && cnt < k) cnt += s[r++] - '0';
      if (cnt == k) mlen = min(mlen, r - l);
      cnt -= s[l] - '0';
    }
    if (mlen == N + 1) return "";

    r = 0; string ans(mlen, '1');
    for (int l = 0; l < N; ++l) {
      while (r < N && cnt < k) cnt += s[r++] - '0';
      if (cnt == k && r - l == mlen) {
        ans = min(ans, s.substr(l, mlen));
      }
      cnt -= s[l] - '0';
    }
    return ans;
  }
};
