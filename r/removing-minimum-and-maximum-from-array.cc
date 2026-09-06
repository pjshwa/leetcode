class Solution {
public:
  int minimumDeletions(vector<int>& nums) {
    int N = nums.size(), minx = nums[0], maxx = nums[0], mini = 0, maxi = 0;
    for (int i = 0; i < N; ++i) {
      if (nums[i] < minx) minx = nums[i], mini = i;
      if (nums[i] > maxx) maxx = nums[i], maxi = i;
    }
    int left = max(mini, maxi) + 1;
    int right = N - min(mini, maxi);
    int both = (mini < maxi ? mini + 1 : maxi + 1) + (mini < maxi ? N - maxi : N - mini);
    return min({left, right, both});
  }
};
