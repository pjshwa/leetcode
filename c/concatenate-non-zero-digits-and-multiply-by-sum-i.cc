#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
  long long sumAndMultiply(int n) {
    ll l = 0, s = 0;
    stack<int> ds;
    while (n) {
      int d = n % 10;
      if (d) ds.push(d);
      n /= 10;
    }
    while (!ds.empty()) {
      int d = ds.top(); ds.pop();
      l = (l * 10 + d);
      s = (s + d);
    }
    return l * s;
  }
};
