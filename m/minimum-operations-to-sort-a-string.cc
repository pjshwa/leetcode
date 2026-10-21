#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minOperations(string s) {
    int N = s.size(); auto t = s;
    sort(t.begin(), t.end());
    if (s == t) return 0;
    if (N == 2) return -1;
    if (s[0] == t[0] || s[N - 1] == t[N - 1]) return 1;

    for (int i = 1; i < N - 1; ++i) {
      if (s[i] == t[0] || s[i] == t[N - 1]) return 2;
    }
    return 3;
  }
};
