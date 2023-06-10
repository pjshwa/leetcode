using ll = long long;

class Solution {
  ll upto(ll n) {
    return n * (n + 1) / 2;
  }

public:
  int maxValue(int n, int index, int maxSum) {
    int left = 1, right = maxSum + 1;
    while (left < right) {
      int mid = (left + right) / 2;
      int v = mid - 1;

      ll total = mid;
      for (int len : {index, n - index - 1}) {
        if (len >= v) total += upto(v) + (len - v);
        else total += upto(v) - upto(v - len);
      }

      if (total <= maxSum) left = mid + 1;
      else right = mid;
    }
    return left - 1;
  }
};
