class Solution {
public:
  int numSubarraysWithSum(vector<int>& nums, int goal) {
    map<int, int> t; t[0] = 1;
    int dt = 0, ans = 0;
    for (int e : nums) {
      dt += e;
      ans += t[dt - goal];
      ++t[dt];
    }
    return ans;
  }
};
