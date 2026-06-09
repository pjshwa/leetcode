class Solution {
public:
  long long maxTotalValue(vector<int>& nums, int k) {
    int nmax = INT_MIN, nmin = INT_MAX;
    for (int e : nums) {
      nmax = max(nmax, e);
      nmin = min(nmin, e);
    }
    return (long long)(nmax - nmin) * k;
  }
};
