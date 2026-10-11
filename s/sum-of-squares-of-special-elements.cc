class Solution {
public:
  int sumOfSquares(vector<int>& nums) {
    int ans = 0, i = 0, N = nums.size();
    for (int e : nums) {
      if (N % ++i) continue;
      ans += e * e;
    }
    return ans;
  }
};
