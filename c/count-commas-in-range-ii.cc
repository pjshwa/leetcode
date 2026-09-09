class Solution {
public:
  long long countCommas(long long n) {
    long long ans = 0, w = 1000;
    while (w <= n) {
      ans += n - w + 1;
      w *= 1000;
    }
    return ans;
  }
};
