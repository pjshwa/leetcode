class Solution {
public:
  int splitArray(vector<int>& nums, int m) {
    int left = *max_element(nums.begin(), nums.end()), right = 1e9 + 1;
    while (left < right) {
      int mid = left + (right - left) / 2;

      int running = 0, cnt = 1;
      for (int i = 0; i < nums.size(); ++i) {
        if (running + nums[i] > mid) {
          running = 0;
          ++cnt;
        }
        running += nums[i];
      }

      if (cnt <= m) right = mid;
      else left = mid + 1;
    }
    return left;
  }
};
