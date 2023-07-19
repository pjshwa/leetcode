class Solution {
public:
  int maximumGap(vector<int>& nums) {
    long long N = nums.size();
    if (N == 1) return 0;

    int minH = INT_MAX, maxH = INT_MIN;
    for (int i = 0; i < N; i++) {
      minH = min(minH, nums[i]);
      maxH = max(maxH, nums[i]);
    }
    if (minH == maxH) return 0;

    vector<int> minV(N + 1, INT_MAX), maxV(N + 1, INT_MIN);
    for (int i = 0; i < N; i++) {
      int idx = (nums[i] - minH) * N / (maxH - minH);
      minV[idx] = min(minV[idx], nums[i]);
      maxV[idx] = max(maxV[idx], nums[i]);
    }

    int last = maxV[0], ans = 0;
    for (int i = 1; i <= N; i++) {
      if (minV[i] == INT_MAX) continue;
      ans = max(ans, minV[i] - last);
      last = maxV[i];
    }
    return ans;
  }
};
