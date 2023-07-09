const int INF = 0x3f3f3f3f;

class Solution {
public:
  int maximumJumps(vector<int>& nums, int target) {
    int N = nums.size();

    int d[N]; d[0] = 0;
    for (int i = 1; i < N; i++) {
      d[i] = -INF;
      for (int j = 0; j < i; j++) {
        if (d[j] == -INF) continue;

        int diff = nums[i] - nums[j];
        if (-target <= diff && diff <= target) {
          d[i] = max(d[i], d[j] + 1);
        }
      }
    }

    if (d[N - 1] == -INF) return -1;
    else return d[N - 1];
  }
};
