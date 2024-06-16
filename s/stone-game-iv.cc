class Solution {
  bool d[100'001];
public:
  bool winnerSquareGame(int n) {
    d[0] = 0;
    for (int i = 1; i <= n; i++) {
      d[i] = 0;
      for (int j = 1; i - j * j >= 0; j++) {
        if (!d[i - j * j]) {
          d[i] = 1;
          break;
        }
      }
    }
    return d[n];
  }
};
