class Solution {
public:
  int subarraysWithKDistinct(vector<int>& nums, int k) {
    int ans = 0, r1 = 0, r2 = 0, N = nums.size();
    map<int, int> m1, m2;
    for (int l = 0; l < N; ++l) {
      while (r1 < N && m1.size() < k) m1[nums[r1++]]++;
      while (r2 < N && m2.size() <= k) m2[nums[r2++]]++;

      if (m2.size() > k) ans += r2 - r1;
      else if (m1.size() == k) ans += N + 1 - r1;
      
      if (--m1[nums[l]] == 0) m1.erase(nums[l]);
      if (--m2[nums[l]] == 0) m2.erase(nums[l]);
    }
    return ans;
  }
};
