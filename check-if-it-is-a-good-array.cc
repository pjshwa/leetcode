class Solution {
public:
  bool isGoodArray(vector<int>& nums) {
    int g = 0;
    for (int e : nums) g = gcd(g, e);
    return g == 1;
  }
};
