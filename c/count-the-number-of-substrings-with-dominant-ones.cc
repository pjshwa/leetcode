class Solution {
public:
  int numberOfSubstrings(string s) {
    int N = s.size();
    vector<int> P0(N + 1, 0), P1(N + 1, 0), nxt0(N + 2, N + 1);
    for (int i = 0; i < N; ++i) {
      P0[i + 1] = P0[i] + (s[i] == '0');
      P1[i + 1] = P1[i] + (s[i] == '1');
    }
    for (int i = N; i >= 1; --i) {
      nxt0[i] = (s[i - 1] == '0' ? i : nxt0[i + 1]);
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
      int zi = nxt0[i], zc = 0;
      ans += zi - i;
      while (zc * zc <= N && zi <= N) {
        int nzi = nxt0[zi + 1]; ++zc;
        int oi = min(N, nzi);
        int len = P1[oi] - P1[zi] + 1;
        int squ_oc = P1[oi] - P1[i - 1] - zc * zc + 1;
        ans += max(0, min(len, squ_oc));
        zi = nzi;
      }
    }
    return ans;
  }
};
