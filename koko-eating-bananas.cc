class Solution {
public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1, right = 1e9;
    while (left < right) {
      int mid = (left + right) / 2;
      long long ct = 0;
      for (int pile : piles) ct += (pile - 1) / mid + 1;

      if (ct > h) left = mid + 1;
      else right = mid;
    }
    return left;
  }
};
