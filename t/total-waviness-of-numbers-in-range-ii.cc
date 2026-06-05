#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
  ll dp_s[20][10][10][2][4], dp_c[20][10][10][2][4];
  string s; int sz;

  pair<ll, ll> rec(int i, int p1, int p2, int f, int z) {
    if (i == sz) return {0, 1};
    if (dp_s[i][p1][p2][f][z] != -1) return {dp_s[i][p1][p2][f][z], dp_c[i][p1][p2][f][z]};

    ll sum = 0, cnt = 0;
    for (int d = 0; d < 10; ++d) {
      if (f && d > s[i] - '0') break;
      int nz = z == 0 && d == 0 ? 0 : min(3, z + 1);
      int ok = nz == 3 && i > 1 && ((d > p1 && p1 < p2) || (d < p1 && p1 > p2));
      auto [csum, ccnt] = rec(i + 1, d, p1, f && (d == s[i] - '0'), nz);
      sum += csum + ok * ccnt; cnt += ccnt;
    }
    return {dp_s[i][p1][p2][f][z] = sum, dp_c[i][p1][p2][f][z] = cnt};
  }

  ll upto(ll n) {
    if (n < 100) return 0;
    s = to_string(n); sz = s.size();
    memset(dp_s, -1, sizeof(dp_s));
    memset(dp_c, -1, sizeof(dp_c));
    return rec(0, 0, 0, 1, 0).first;
  }

public:
  ll totalWaviness(ll num1, ll num2) {
    return upto(num2) - upto(num1 - 1);
  }
};
