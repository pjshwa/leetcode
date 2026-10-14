class Solution {
public:
  string maxSumOfSquares(int num, int sum) {
    string ans = "";
    for (int i = 0; i < num; ++i) {
      int d = min(sum, 9);
      ans += d + '0'; sum -= d;
    }
    return sum ? "" : ans;
  }
};
