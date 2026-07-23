class Solution {
public:
  int uniqueXorTriplets(vector<int>& nums) {
    int c = 1, n = nums.size();
    while (c <= n) c *= 2;
    return n <= 2 ? n : c;
  }
};
