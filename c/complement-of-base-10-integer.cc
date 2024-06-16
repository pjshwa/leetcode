class Solution {
public:
  int bitwiseComplement(unsigned int n) {
    if (n == 0) return 1;
    unsigned int mask = (1LL << 31) - 1;
    while (((mask >> 1) & n) == n) mask >>= 1;
    return n ^ mask;
  }
};
