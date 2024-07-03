class Solution {
public:
  int minDifference(vector<int>& nums) {
    int N = nums.size();
    if (N <= 3) return 0;

    sort(nums.begin(), nums.end()); int ans = INT_MAX;
    for (int d = 0; d <= 3; ++d) {
      int dif = nums[N - 4 + d] - nums[d];
      ans = min(ans, dif);
    }
    return ans;
  }
};
