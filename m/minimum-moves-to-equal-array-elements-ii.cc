class Solution {
public:
  int minMoves2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int N = nums.size(), v = nums[N / 2], ans = 0;
    for (int e : nums) ans += abs(v - e);
    return ans;
  }
};
