class Solution {
public:
  long long flowerGame(int n, int m) {
    int ec = m / 2, oc = m - ec;
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (i & 1) ans += ec;
      else ans += oc;
    }
    return ans;
  }
};
