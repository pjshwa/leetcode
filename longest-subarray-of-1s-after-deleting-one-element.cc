class Solution {
public:
  int longestSubarray(vector<int>& nums) {
    int N = nums.size();

    int SL[N + 10], SR[N + 10];
    SL[0] = SR[N + 1] = 0;
    for (int i = 1; i <= N; i++) SL[i] = nums[i - 1] ? SL[i - 1] + 1 : 0;
    for (int i = N; i >= 1; i--) SR[i] = nums[i - 1] ? SR[i + 1] + 1 : 0;

    int ans = 0;
    for (int i = 1; i <= N; i++) ans = max(ans, SL[i - 1] + SR[i + 1]);
    return ans;
  }
};
