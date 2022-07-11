#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

class Solution {
  bool rc[10], gc[10], bc[10];
public:
  int countPoints(string rings) {
    memset(rc, 0, sizeof(rc));
    memset(gc, 0, sizeof(gc));
    memset(bc, 0, sizeof(bc));

    int n = rings.size() / 2;
    for (int i = 0; i < n; i++) {
      int ci = 2 * i, cj = 2 * i + 1;
      if (rings[ci] == 'R') rc[rings[cj] - '0'] = true;
      if (rings[ci] == 'G') gc[rings[cj] - '0'] = true;
      if (rings[ci] == 'B') bc[rings[cj] - '0'] = true;
    }

    int ans = 0;
    for (int i = 0; i < 10; i++) {
      if (rc[i] && gc[i] && bc[i]) ans++;
    }

    return ans;
  }
};

int main() {
  // cout << (new Solution())->closestCost({1, 7}, {3, 4}, 10) << endl;
  // cout << (new Solution())->closestCost({3, 10}, {2, 5}, 9) << endl;
  // cout << (new Solution())->closestCost({2, 3}, {4, 5, 100}, 18) << endl;
  // cout << (new Solution())->closestCost({10}, {1}, 1) << endl;
}
