class Solution {
public:
  int maxSum(vector<int>& nums) {
    set<int> U = {nums.begin(), nums.end()};
    if (*U.rbegin() < 0) return *U.rbegin();

    int ans = 0;
    for (int e : U) if (e > 0) ans += e;
    return ans;
  }
};
