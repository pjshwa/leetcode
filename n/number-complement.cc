class Solution {
public:
  int findComplement(unsigned int num) {
    unsigned int mask = (1LL << 31) - 1;
    while (((mask >> 1) & num) == num) mask >>= 1;
    return num ^ mask;
  }
};
