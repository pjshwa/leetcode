class Solution {
public:
  int minimumRightShifts(vector<int>& nums) {
    int N = nums.size();
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
      if (nums[i] < nums[(i - 1 + N) % N]) cnt++;
    }
    if (cnt > 1) return -1;

    for (int i = 0; i < N; ++i) {
      if (nums[i] < nums[(i - 1 + N) % N]) return (N - i) % N;
    }
    return 0;
  }
};
