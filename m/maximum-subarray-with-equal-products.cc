const int MAXP = 25200;

class Solution {
  int lcm(int a, int b) {
    return a / __gcd(a, b) * b;
  }

public:
  int maxLength(vector<int>& nums) {
    int N = nums.size(), ans = 0;
    for (int i = 0; i < N; ++i) {
      int prod = 1, l = 1, g = 0;
      for (int j = i; j < N; ++j) {
        prod *= nums[j];
        if (prod > MAXP) break;
        l = lcm(l, nums[j]), g = __gcd(g, nums[j]);
        if (prod == l * g) ans = max(ans, j - i + 1);
      }
    }
    return ans;
  }
};
