class Solution {
  long long d[5001];
public:
  int change(int amount, vector<int>& coins) {
    memset(d, 0, sizeof(d));
    d[0] = 1;
    for (int coin : coins) {
      for (int w = 0; w <= 5000; w++) {
        if (w >= coin) d[w] += d[w - coin];
      }
    }
    return d[amount];
  }
};
