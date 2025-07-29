class Solution {
public:
  vector<int> smallestSubarrays(vector<int>& nums) {
    int N = nums.size();
    vector<int> maxOr(N, nums.back());
    for (int i = N - 2; i >= 0; --i) maxOr[i] = (maxOr[i + 1] | nums[i]);

    vector<int> res(N); int B[30] = {0}, r = 0;
    auto getOr = [&] {
      int ans = 0;
      for (int j = 0; j < 30; ++j) if (B[j]) ans |= (1 << j);
      return ans;
    };
    for (int l = 0; l < N; ++l) {
      while (r < N && (getOr() < maxOr[l] || r <= l)) {
        for (int j = 0; j < 30; ++j) if (nums[r] & (1 << j)) ++B[j];
        r++;
      }
      res[l] = r - l;
      for (int j = 0; j < 30; ++j) if (nums[l] & (1 << j)) --B[j];
    }
    return res;
  }
};
