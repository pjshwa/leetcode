class Solution {
public:
  int minMoves(vector<int>& nums) {
    int mmax = *max_element(nums.begin(), nums.end()), ans = 0;
    for (int e : nums) ans += mmax - e;
    return ans;
  }
};
