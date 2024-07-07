class Solution {
public:
  int numWaterBottles(int numBottles, int numExchange) {
    int ans = 0;
    while (numBottles >= numExchange) {
      numBottles -= numExchange - 1;
      ans += numExchange;
    }
    return ans + numBottles;
  }
};
