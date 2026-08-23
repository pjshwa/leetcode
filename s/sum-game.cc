#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool sumGame(string num) {
    int N = num.size(), dif = 0, q = 0;
    for (int i = 0; i < N / 2; ++i) {
      if (num[i] == '?') ++q;
      else dif += num[i] - '0';
    }
    for (int i = N / 2; i < N; ++i) {
      if (num[i] == '?') --q;
      else dif -= num[i] - '0';
    }
    if (q % 2 || (long long)dif * q > 0) return true;
    return abs(dif) != 9 * (abs(q) / 2);
  }
};
