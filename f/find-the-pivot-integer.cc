class Solution {
public:
  int pivotInteger(int n) {
    int sum = n * (n + 1) / 2;
    int q = sqrt(sum);
    if (q * q == sum) return q;
    return -1;
  }
};
