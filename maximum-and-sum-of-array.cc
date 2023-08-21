const int INF = 0x3f3f3f3f;

class Solution {
  int dp[20][1 << 18];
public:
  int maximumANDSum(vector<int>& nums, int numSlots) {
    int N = nums.size();

    int all_s = 1 << N;
    for (int i = 0; i < 20; i++) fill(dp[i], dp[i] + all_s, -INF);
    dp[0][0] = 0;

    for (int z = 1; z <= 2 * numSlots; z++) {
      int slot = (z + 1) / 2;

      for (int state = 0; state < all_s; state++) {
        // put none
        dp[z][state] = dp[z - 1][state];

        // put one
        for (int i = 0; i < N; i++) {
          if (!(state & (1 << i))) continue;
          dp[z][state] = max(
            dp[z][state],
            dp[z - 1][state ^ (1 << i)] + (nums[i] & slot)
          );
        }
      }
    }

    return dp[2 * numSlots][all_s - 1];
  }
};
