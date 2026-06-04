#include <bits/stdc++.h>
using namespace std;

class Solution {
  int f(int n) {
    string s = to_string(n);
    int z = s.size(), ret = 0;
    for (int i = 1; i < z - 1; ++i) {
      if ((s[i] > s[i - 1] && s[i] > s[i + 1]) ||
          (s[i] < s[i - 1] && s[i] < s[i + 1])) ++ret;
    }
    return ret;
  }

public:
  int totalWaviness(int num1, int num2) {
    int ans = 0;
    for (int i = num1; i <= num2; ++i) ans += f(i);
    return ans;
  }
};
