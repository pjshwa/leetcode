class Solution {
public:
  int maximumUniqueSubarray(vector<int>& nums) {
    int ep = 0, n = nums.size(), ans = 0, cur = 0;
    map<int, int> r;
    for (int sp = 0; sp < n; sp++) {
      while (ep < n && r[nums[ep]] == 0) {
        cur += nums[ep];
        r[nums[ep]]++;
        ep++;
      }

      ans = max(ans, cur);
      cur -= nums[sp];
      r[nums[sp]]--;
    }
    return ans;
  }
};
