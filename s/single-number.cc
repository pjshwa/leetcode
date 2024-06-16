class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int e : nums) ans ^= (e + 40000);
    return ans - 40000;
  }
};
