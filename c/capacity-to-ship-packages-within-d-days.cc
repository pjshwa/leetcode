const int INF = 0x3f3f3f3f;

class Solution {
public:
  int shipWithinDays(vector<int>& weights, int days) {
    int left = 0, right = 1;
    for (int w : weights) left = max(left, w), right += w;

    int n = weights.size();
    while (left < right) {
      int mid = (left + right) / 2;
      int d = 1, sum = 0;
      for (int i = 0; i < n; i++) {
        if (sum + weights[i] > mid) d++, sum = 0;
        sum += weights[i];
      }
      if (d > days) left = mid + 1;
      else right = mid;
    }

    return left;
  }
};
