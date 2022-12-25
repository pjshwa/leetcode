class Solution {
public:
  int maximumTastiness(vector<int>& price, int k) {
    int n = price.size();
    sort(price.begin(), price.end());

    int left = 1, right = 1e9 + 1;
    while (left < right) {
      int mid = (left + right) / 2, cnt = 1;

      int L = price[0];
      for (int i = 1; i < n; i++) {
        if (price[i] - L >= mid) {
          cnt++;
          L = price[i];
        }
      }

      if (cnt >= k) left = mid + 1;
      else right = mid;
    }

    return left - 1;
  }
};
