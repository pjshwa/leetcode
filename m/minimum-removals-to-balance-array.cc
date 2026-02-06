class Solution {
public:
  int minRemoval(vector<int>& nums, int k) {
    int N = nums.size(), r = 0, ans = N;
    sort(nums.begin(), nums.end());
    for (int l = 0; l < N; ++l) {
      while (r < N && nums[r] <= (long long)nums[l] * k) ++r;
      ans = min(ans, N - (r - l));
    }
    return ans;
  }
};
