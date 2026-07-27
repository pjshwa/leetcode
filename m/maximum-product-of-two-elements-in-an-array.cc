class Solution {
public:
  int maxProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int e1 = nums.back(); nums.pop_back();
    int e2 = nums.back(); nums.pop_back();
    return (e1 - 1) * (e2 - 1);
  }
};
