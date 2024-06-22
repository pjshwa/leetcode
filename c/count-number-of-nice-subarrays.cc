class Solution {
public:
  int numberOfSubarrays(vector<int>& nums, int k) {
    map<int, int> mdt; mdt[0] = 1; int dt = 0, ans = 0;
    for (int e : nums) {
      dt += e % 2;
      ans += mdt[dt - k];
      ++mdt[dt];
    }
    return ans;
  }
};
