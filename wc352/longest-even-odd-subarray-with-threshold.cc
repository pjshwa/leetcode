class Solution {
public:
  int longestAlternatingSubarray(vector<int>& nums, int threshold) {
    int N = nums.size();

    int ans = 0;
    for (int i = 0; i < N; i++) {
      if (nums[i] % 2) continue;
      if (nums[i] > threshold) continue;

      ans = max(ans, 1);
      for (int j = i + 1; j < N; j++) {
        if (nums[j] % 2 == nums[j - 1] % 2) break;
        if (nums[j] > threshold) break;
        ans = max(ans, j - i + 1);
      }
    }

    return ans;
  }
};
