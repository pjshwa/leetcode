class Solution {
public:
  int findMaxLength(vector<int>& nums) {
    int dt = 0, N = nums.size(), ans = 0;
    map<int, int> mp; mp[0] = -1;
    for (int i = 0; i < N; ++i) {
      dt += (nums[i] == 0) ? -1 : 1;
      if (mp.count(dt)) ans = max(ans, i - mp[dt]);
      else mp[dt] = i;
    }
    return ans;
  }
};
