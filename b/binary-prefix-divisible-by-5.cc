class Solution {
public:
  vector<bool> prefixesDivBy5(vector<int>& nums) {
    vector<bool> res; int sum = 0;
    for (int e : nums) {
      sum = (2 * sum + e) % 5;
      res.push_back(!sum);
    }
    return res;
  }
};
