class Solution {
  int d[40001];
public:
  int coinChange(vector<int>& coins, int amount) {
    for (int w = 0; w <= 40000; w++) d[w] = 1e9;
    d[0] = 0;
    for (int coin : coins) {
      for (int w = 0; w <= 40000; w++) {
        if (w >= coin) d[w] = min(d[w], d[w - coin] + 1);
      }
    }
    return d[amount] == 1e9 ? -1 : d[amount];
  }
};
