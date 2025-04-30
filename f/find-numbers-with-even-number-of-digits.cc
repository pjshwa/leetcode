class Solution {
public:
  int findNumbers(vector<int>& nums) {
    int ans = nums.size();
    for (int e : nums) ans -= (to_string(e).size() & 1);
    return ans;
  }
};
