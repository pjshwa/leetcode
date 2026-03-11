class Solution {
public:
  int bitwiseComplement(int n) {
    int x = 1;
    while (x < n) x = 2 * x + 1;
    return x - n;
  }
};
