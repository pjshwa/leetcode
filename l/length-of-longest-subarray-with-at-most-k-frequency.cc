class Solution {
public:
  int maxSubarrayLength(vector<int>& nums, int k) {
    int N = nums.size(), ans = 0, r = 0;
    map<int, int> tal;
    for (int l = 0; l < N; ++l) {
      while (r < N && tal[nums[r]] < k) tal[nums[r++]]++;
      ans = max(ans, r - l);
      tal[nums[l]]--;
    }
    return ans;
  }
};
