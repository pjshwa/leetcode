#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
  char processStr(string s, ll k) {
    ll N = 0; string ops;
    for (char c : s) {
      int f = 1;
      if (c == '#') N *= 2;
      else if (c == '*') {
        if (N > 0) --N;
        else f = 0;
      }
      else if (c != '%') ++N;
      if (f) ops.push_back(c);
    }
    if (k >= N) return '.';

    while (!ops.empty()) {
      char c = ops.back(); ops.pop_back();
      if (c == '#') {
        assert(N % 2 == 0);
        N /= 2;
        k %= N;
      }
      else if (c == '*') ++N;
      else if (c == '%') k = N - 1 - k;
      else {
        if (k + 1 == N) return c;
        --N;
      }
    }
    return '.';
  }
};
