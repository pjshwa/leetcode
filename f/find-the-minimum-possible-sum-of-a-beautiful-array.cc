class Solution {
public:
  long long minimumPossibleSum(int n, int target) {
    long long ans = 0;
    for (int i = 1; i <= min(n, target / 2); i++) ans += i;
    for (int i = target; i < target + (n - target / 2); i++) ans += i;
    return ans;
  }
};
