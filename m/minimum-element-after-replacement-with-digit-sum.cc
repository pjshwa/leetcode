class Solution {
  int dsum(int n) {
    int sum = 0;
    while (n > 0) {
      sum += n % 10;
      n /= 10;
    }
    return sum;
  }

public:
  int minElement(vector<int>& nums) {
    int ans = INT_MAX;
    for (int e : nums) ans = min(ans, dsum(e));
    return ans;
  }
};
