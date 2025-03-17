class Solution {
public:
  bool divideArray(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    while (!nums.empty()) {
      int x1 = nums.back(); nums.pop_back();
      int x2 = nums.back(); nums.pop_back();
      if (x1 != x2) return false;
    }
    return true;
  }
};
