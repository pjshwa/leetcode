class Solution {
public:
  int totalMoney(int n) {
    int ans = 0, iter = (n - 1) / 7;
    for (int d = 0; d < 7; ++d) {
      int ttl = iter + ((n - 1) % 7 >= d);
      ans += ttl * (ttl + 1) / 2;
      ans += ttl * d;
    }
    return ans;
  }
};
