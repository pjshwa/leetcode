using ll = long long;
using pii = pair<int, int>;

class Solution {
public:
  int countPairs(vector<vector<int>>& coordinates, int k) {

    map<pii, int> tal; ll ans = 0;
    for (auto& coord : coordinates) {
      int x = coord[0], y = coord[1];

      for (int k1 = 0; k1 <= k; ++k1) {
        int k2 = k - k1;
        int x_inv = x ^ k1, y_inv = y ^ k2;
        ans += tal[{x_inv, y_inv}];
      }

      tal[{x, y}]++;
    }

    return ans;
  }
};
