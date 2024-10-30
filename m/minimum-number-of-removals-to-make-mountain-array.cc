class Solution {
public:
  int minimumMountainRemovals(vector<int>& nums) {
    int N = nums.size(), ans = 0;
    vector<int> LIS_L(N, 1), LIS_R(N, 1);
    for (int i = 0; i < N; i++) for (int j = 0; j < i; j++) {
      if (nums[j] < nums[i]) LIS_L[i] = max(LIS_L[i], LIS_L[j] + 1);
    }
    for (int i = N - 1; i >= 0; i--) for (int j = N - 1; j > i; j--) {
      if (nums[j] < nums[i]) LIS_R[i] = max(LIS_R[i], LIS_R[j] + 1);
    }
    for (int i = 1; i < N - 1; i++) {
      if (LIS_L[i] == 1 || LIS_R[i] == 1) continue;
      ans = max(ans, LIS_L[i] + LIS_R[i] - 1);
    }
    return N - ans;
  }
};
