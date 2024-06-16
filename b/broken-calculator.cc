class Solution {
public:
  int brokenCalc(int x, int y) {
    int count = 0;
    while (y != x) {
      if (x >= y) return x - y + count;

      /* If y is even, the last move was multiplication, else decrement */
      if (y % 2 == 0) y = y / 2;
      else y++;

      // One operation used
      count++;
    }
    return count;
  }
};
