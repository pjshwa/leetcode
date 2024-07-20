class Solution {
public:
  vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    int N = rowSum.size(), M = colSum.size(), i = 0, j = 0;
    vector<vector<int>> ans(N, vector<int>(M));
    while (i < N && j < M) {
      int val = min(rowSum[i], colSum[j]);
      ans[i][j] = val; rowSum[i] -= val; colSum[j] -= val;
      if (rowSum[i] == 0) ++i;
      else ++j;
    }
    return ans;
  }
};
