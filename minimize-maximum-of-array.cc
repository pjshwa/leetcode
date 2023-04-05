using ll = long long;

class Solution {
public:
  int minimizeArrayValue(vector<int>& nums) {
    int l = 0, r = 1e9 + 1, n = nums.size();
    while (l < r) {
      int m = (l + r) / 2;
      vector<ll> B{nums.begin(), nums.end()};
      for (int i = n - 1; i >= 1; i--) {
        if (B[i] <= m) continue;
        ll diff = B[i] - m;
        B[i] = m; B[i - 1] += diff;
      }

      if (B[0] <= m) r = m;
      else l = m + 1;
    }
    return l;
  }
};
