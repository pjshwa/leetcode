class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    int N = nums.size(), M = 0;
    for (auto &row : nums) M = max(M, (int)row.size());

    vector<vector<int>> S(N + M);
    for (int i = 0; i < N; ++i) for (int j = 0; j < nums[i].size(); ++j) {
      S[i + j].push_back(nums[i][j]);
    }

    vector<int> ans;
    for (auto &row : S) {
      reverse(row.begin(), row.end());
      for (auto &x : row) ans.push_back(x);
    }
    return ans;
  }
};
