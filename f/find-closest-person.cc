class Solution {
public:
  int findClosest(int x, int y, int z) {
    int xd = abs(x - z), yd = abs(y - z);
    if (xd == yd) return 0;
    else if (xd < yd) return 1;
    else return 2;
  }
};
