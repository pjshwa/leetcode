class Solution {
public:
  int maximumCount(vector<int>& nums) {
    int pos = 0, neg = 0;
    for (int e : nums) {
      if (e > 0) ++pos;
      if (e < 0) ++neg;
    }
    return max(pos, neg);
  }
};
