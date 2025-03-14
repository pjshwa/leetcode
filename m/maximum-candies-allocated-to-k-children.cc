class Solution {
public:
  int maximumCandies(vector<int>& candies, long long k) {
    int l = 1, r = *max_element(candies.begin(), candies.end()) + 1;
    while (l < r) {
      long long m = (l + r) / 2, cnt = 0;
      for (int c : candies) cnt += c / m;
      if (cnt >= k) l = m + 1;
      else r = m;
    }
    return l - 1;
  }
};
