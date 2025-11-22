class Solution {
public:
  int minimumOperations(vector<int>& nums) {
    int ans = 0;
    for (int e : nums) ans += (e % 3 != 0);
    return ans;
  }
};
