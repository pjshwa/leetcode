class Solution {
public:
  char findKthBit(int n, int k) {
    if (n == 1) return '0';

    int sz = 1 << n, h = sz / 2;
    if (k == h) return '1';
    else if (k < h) return findKthBit(n - 1, k);
    else return findKthBit(n - 1, sz - k) == '0' ? '1' : '0';
  }
};
