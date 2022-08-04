class Solution {
public:
  int mirrorReflection(int p, int q) {
    int g = __gcd(p, q), l = p / g * q;
    int w = l / q, h = l / p;

    if (h & 1) {
      if (w & 1) return 1;
      else return 2;
    }
    else {
      if (w & 1) return 0;
      else return 1;
    }
  }
};
