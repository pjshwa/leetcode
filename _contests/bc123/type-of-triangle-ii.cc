class Solution {
public:
  string triangleType(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int x = nums[0], y = nums[1], z = nums[2];
    if (x + y <= z) return "none";

    if (x == y && y == z) return "equilateral";
    if (x == y || y == z) return "isosceles";
    return "scalene";
  }
};
