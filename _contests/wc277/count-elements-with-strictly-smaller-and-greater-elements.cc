class Solution {
public:
  int countElements(vector<int>& nums) {
    map<int, int> t;

    int mn = 1e9, mx = -1e9;
    for (auto& n : nums) {
      t[n]++;
      mn = min(mn, n);
      mx = max(mx, n);
    }

    int ans = 0;
    for (auto [k, v] : t) {
      if (k != mn && k != mx) ans += v;
    }
    return ans;
  }
};