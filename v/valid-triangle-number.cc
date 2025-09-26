class Solution {
public:
  int triangleNumber(vector<int>& nums) {
    int N = nums.size(), ans = 0;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < N; ++i) {
      int k = i + 2;
      for (int j = i + 1; j < N; ++j) {
        int a = nums[i], b = nums[j];
        while (k < N && a + b > nums[k]) ++k;
        if (j < k) ans += k - j - 1;
      }
    }
    return ans;
  }
};
