class Solution {
public:
  vector<int> constructTransformedArray(vector<int>& nums) {
    int N = nums.size();
    vector<int> res(N);
    for (int i = 0; i < N; ++i) {
      int j = (i + nums[i]) % N;
      if (j < 0) j += N;
      res[i] = nums[j];
    }
    return res;
  }
};
