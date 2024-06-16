class Solution {
public:
  int specialArray(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int p = 0, N = nums.size();
    for (int x = 0; x <= N; ++x) {
      while (p < N && nums[p] < x) ++p;
      if (N - p == x) return x;
    }
    return -1;
  }
};
