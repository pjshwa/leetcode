using ll = long long;
const int MOD = 1e9 + 7;

class Solution {

public:
  int countTrapezoids(vector<vector<int>>& points) {
    sort(points.begin(), points.end(),
         [](const vector<int>& a, const vector<int>& b) {
           return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
         });

    ll pre = 0, px = 0, py = -1e9, acc = 0, cur = 0, ans = 0;
    for (auto& pt : points) {
      int cx = pt[0], cy = pt[1];
      if (py == cy) {
        cur += ++acc;
      } else {
        ll add = pre * cur % MOD;
        ans = (ans + add) % MOD;
        pre = (pre + cur) % MOD;
        cur = acc = 0;
      }
      px = cx; py = cy;
    }

    ll add = pre * cur % MOD;
    ans = (ans + add) % MOD;
    return ans;
  }
};
