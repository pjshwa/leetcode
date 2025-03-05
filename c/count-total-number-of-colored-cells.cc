class Solution {
public:
  long long coloredCells(int n) {
    long long ans = n;
    ans *= 2 * n;
    return ans - 2 * n + 1;
  }
};
