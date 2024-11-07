class Solution {
public:
  int largestCombination(vector<int>& candidates) {
    int ans = 0;
    for (int b = 0; b < 24; ++b) {
      int cur = 0;
      for (int e : candidates) if (e & (1 << b)) ++cur;
      ans = max(ans, cur);
    }
    return ans;
  }
};
