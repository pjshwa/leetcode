class Solution {
public:
  vector<int> minBitwiseArray(vector<int>& nums) {
    vector<int> ans;
    for (int e : nums) {
      int x;
      for (x = 1; x <= e; ++x) {
        int val = x | (x + 1);
        if (val == e) break;
      }
      if (x > e) ans.push_back(-1);
      else ans.push_back(x);
    }
    return ans;
  }
};
