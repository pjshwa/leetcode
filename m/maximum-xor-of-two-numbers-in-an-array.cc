class Solution {
public:
  int findMaximumXOR(vector<int>& nums) {
    uint ans = 0, mask = 0;
    for (int b = 31; b >= 0; --b) {
      mask = mask | (1 << b);
      unordered_set<uint> s;
      for (uint num : nums) s.insert(num & mask);

      uint t = ans | (1 << b);
      for (int prefix : s) {
        if (s.count(t ^ prefix)) {
          ans = t;
          break;
        }
      }
    }

    return ans;
  }
};
