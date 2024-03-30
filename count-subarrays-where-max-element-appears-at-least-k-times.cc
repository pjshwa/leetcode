class Solution {
public:
  long long countSubarrays(vector<int>& nums, int k) {
    long long ans = 0, r = 0, N = nums.size(), cnt = 0, maxv = *max_element(nums.begin(), nums.end());
    for (int l = 0; l < N; ++l) {
      while (r < N && cnt < k) {
        if (nums[r] == maxv) ++cnt;
        ++r;
      }
      if (cnt == k) ans += N - r + 1;
      if (nums[l] == maxv) --cnt;
    }
    return ans;
  }
};
