class Solution {
public:
  int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int N = nums.size(), Q = queries.size();
    vector<int> P(N + 1);

    int l = 0, r = Q + 1;
    while (l < r) {
      int m = (l + r) / 2;
      fill(P.begin(), P.end(), 0);
      for (int i = 0; i < m; ++i) {
        int val = queries[i][2];
        P[queries[i][0]] += val;
        P[queries[i][1] + 1] -= val;
      }

      int dt = 0, ok = 1;
      for (int i = 0; i < N; ++i) {
        dt += P[i];
        ok &= dt >= nums[i];
      }
      if (ok) r = m;
      else l = m + 1;
    }
    return l == Q + 1 ? -1 : l;
  }
};
