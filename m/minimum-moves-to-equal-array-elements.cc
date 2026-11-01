class Solution {
public:
  int minMoves(vector<int>& nums) {
    int minx = *min_element(nums.begin(), nums.end()), ans = 0;
    for (int x : nums) ans += x - minx;
    return ans;
  }
};
