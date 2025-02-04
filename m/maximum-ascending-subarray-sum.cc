class Solution {
public:
  int maxAscendingSum(vector<int>& nums) {
    int last = 101, cur, ans = 0;
    for (int e : nums) {
      if (e > last) cur += e;
      else cur = e;
      last = e;
      ans = max(ans, cur);
    }
    return ans;
  }
};
