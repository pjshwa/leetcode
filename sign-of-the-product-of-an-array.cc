class Solution {
public:
  int arraySign(vector<int>& nums) {
    int ans = 1;
    for (int e : nums) {
      if (e == 0) ans = 0;
      else if (e < 0) ans = -ans;
    }
    return ans;
  }
};
