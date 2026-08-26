class Solution {
public:
  int missingMultiple(vector<int>& nums, int k) {
    set<int> s(nums.begin(), nums.end()); int p = k;
    while (s.count(p)) p += k;
    return p;
  }
};
