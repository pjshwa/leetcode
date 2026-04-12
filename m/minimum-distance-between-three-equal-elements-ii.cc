const int INF = 0x3f3f3f3f;

class Solution {
public:
  int minimumDistance(vector<int>& nums) {
    int N = nums.size();
    vector<vector<int>> by_x(N + 1);
    for (int i = 0; i < N; ++i) by_x[nums[i]].push_back(i);

    int ans = INF;
    for (int x = 0; x <= N; ++x) {
      int Z = by_x[x].size();
      if (Z < 3) continue;

      for (int i = 1; i + 1 < Z; ++i) {
        int d = by_x[x][i + 1] - by_x[x][i - 1];
        ans = min(ans, 2 * d);
      }
    }
    return ans == INF ? -1 : ans;
  }
};
