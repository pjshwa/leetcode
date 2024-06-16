class Solution {
public:
  long long minimumReplacement(vector<int>& nums) {
    reverse(nums.begin(), nums.end());
    int last = nums[0], N = nums.size();

    long long ans = 0;
    for (int i = 1; i < N; i++) {
      if (nums[i] <= last) {
        last = nums[i];
      }
      else {
        long long cnt = (nums[i] + last - 1) / last;
        ans += cnt - 1;

        int l = 1, r = nums[i] + 1;
        while (l < r) {
          int m = (l + r) / 2;
          if (m * cnt > nums[i]) r = m;
          else l = m + 1;
        }

        last = l - 1;
      }
    }

    return ans;
  }
};
