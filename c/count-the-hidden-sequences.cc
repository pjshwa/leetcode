using ll = long long;

class Solution {
public:
  int numberOfArrays(vector<int>& differences, int lower, int upper) {
    ll s = 0, maxs = 0, mins = 0;
    for (int d : differences) {
      s += d;
      maxs = max(maxs, s);
      mins = min(mins, s);
    }
    return max(0LL, (upper - lower) - (maxs - mins) + 1);
  }
};
