#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  const int MOD = 1e9 + 7;
  int d[1001][1001];

  int rearrangeSticks(int n, int k) {
    memset(d, 0, sizeof(d));

    for (int i = 0; i <= n; ++i) d[i][i] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        long long r = d[i - 1][j];
        r = r * (i - 1) % MOD;
        d[i][j] = (r + d[i - 1][j - 1]) % MOD;
      }
    }

    return d[n][k];
  }
};


int main() {
  Solution solution;

  cout << solution.rearrangeSticks(3, 2) << '\n';
  cout << solution.rearrangeSticks(5, 5) << '\n';
  cout << solution.rearrangeSticks(20, 11) << '\n';
}

