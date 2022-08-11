class Solution {
public:
  long long minimumReplacement(vector<int>& nums) {
    int n = nums.size(), lv = nums[n - 1];
    long long ans = 0;

    for (int i = n - 1; i >= 0; i--) {
      if (nums[i] <= lv) {
        lv = nums[i];
        continue;
      }
      int cnt = (nums[i] - 1) / lv + 1;
      ans += cnt - 1;
      lv = nums[i] / cnt;
    }

    return ans;
  }
};
