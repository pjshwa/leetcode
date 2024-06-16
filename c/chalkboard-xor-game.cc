class Solution {
public:
  bool xorGame(vector<int>& nums) {
    int x = 0;
    for (int e : nums) x ^= e;
    return x == 0 || nums.size() % 2 == 0;
  }
};
