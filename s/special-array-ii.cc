class Solution {
public:
  vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
    int N = nums.size();
    vector<int> P(N, 0);
    for (int i = 1; i < N; ++i) P[i] = P[i - 1] + (nums[i] % 2 == nums[i - 1] % 2);

    vector<bool> res;
    for (auto& qv : queries) {
      int qs = qv[0], qe = qv[1];
      res.push_back(P[qs] == P[qe]);
    }
    return res;
  }
};
