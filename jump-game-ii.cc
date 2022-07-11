const int MAX = 10000, INF = 1e9 + 7;

class Solution {
  int d[MAX];
public:
  int jump(vector<int>& nums) {
    fill(d, d + MAX, INF);
    d[0] = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      for (int j = 1; j <= nums[i]; j++) {
        if (i + j >= n) break;
        d[i + j] = min(d[i + j], d[i] + 1);
      }
    }
    return d[n - 1];
  }
};
