class Solution {
public:
  int minOperations(vector<int>& nums) {
    int N = nums.size(), g = 0;
    for (int e : nums) g = gcd(g, e);
    if (g > 1) return -1;

    int ocnt = 0;
    for (int e : nums) if (e == 1) ++ocnt;
    if (ocnt > 0) return N - ocnt;

    int minl = N;
    for (int i = 0; i < N; ++i) {
      int g = nums[i];
      for (int j = i + 1; j < N; ++j) {
        g = gcd(g, nums[j]);
        if (g == 1) {
          minl = min(minl, j - i);
          break;
        }
      }
    }

    return minl + N - 1;
  }
};
