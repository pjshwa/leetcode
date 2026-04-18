class Solution {
  int rev(int x) {
    int ans = 0;
    while (x) {
      ans = ans * 10 + x % 10;
      x /= 10;
    }
    return ans;
  }

public:
  int mirrorDistance(int n) {
    return abs(n - rev(n));
  }
};
