const int MAXV = 1e5;

class Solution {
public:
  int maximumBeauty(vector<int>& nums, int k) {
    vector<int> V(MAXV + 1, 0);
    for (int e : nums) ++V[e];

    int cnt = 0;
    for (int i = 0; i <= min(MAXV, 2 * k); ++i) cnt += V[i];

    int ans = cnt;
    for (int i = 2 * k + 1; i <= MAXV; ++i) {
      cnt += V[i];
      cnt -= V[i - 2 * k - 1];
      ans = max(ans, cnt);
    }

    return ans;
  }
};
