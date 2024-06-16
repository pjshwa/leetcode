class Solution {
public:
  int minImpossibleOR(vector<int>& nums) {
    set<int> s{nums.begin(), nums.end()};
    for (int b = 0; b < 31; b++) {
      if (!s.count(1 << b)) {
        return 1 << b;
      }
    }
    return -1;
  }
};
