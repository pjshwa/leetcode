#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

class Solution {
public:
  int maxTotalFruits(vector<vector<int>> fruits, int startPos, int k) {
    int ans = 0, n = fruits.size();
    priority_queue<pair<int, int>> pq;

    int mi = n;
    for (int i = 0; i < n; ++i) {
      int pi = fruits[i][0], pv = fruits[i][1];
      if (startPos <= pi) {
        if (pi <= startPos + k) {
          pq.push({pi, pv});
          ans += pv;
        }
        mi = min(mi, i);
      }
    }

    int cur = ans;
    for (int i = mi - 1; i >= 0; i--) {
      int pi = fruits[i][0], pv = fruits[i][1];
      int lmove = startPos - pi;
      if (lmove > k) break;

      while (!pq.empty()) {
        auto [ni, nv] = pq.top();
        int rmove = ni - startPos;
        if (lmove + rmove + min(lmove, rmove) > k) {
          pq.pop();
          cur -= nv;
        }
        else break;
      }
      cur += pv;
      ans = max(ans, cur);
    }

    return ans;
  }
};

int main() {
  cout << (new Solution())->maxTotalFruits(
      {{0,7},{7,4},{9,10},{12,6},{14,8},{16,5},{17,8},{19,4},{20,1},{21,3},{24,3},{25,3},{26,1},{28,10},{30,9},{31,6},{32,1},{37,5},{40,9}}, 21, 30) << endl;
  cout << (new Solution())->maxTotalFruits(
      {{2,8},{6,3},{8,6}}, 5, 5) << endl;
}
