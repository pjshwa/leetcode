class Solution {
public:
  double average(vector<int>& salary) {
    double sum = 0;
    int n = salary.size(), smax = INT_MIN, smin = INT_MAX;

    for (auto s : salary) {
      sum += s;
      smax = max(smax, s);
      smin = min(smin, s);
    }

    return (sum - smax - smin) / (n - 2);
  }
};
