class Solution {
public:
  int minOperations(vector<int>& nums) {
    map<int, int> t;
    for (int e : nums) ++t[e];

    int ans = 0;
    for (auto& [_, v] : t) {
      if (v == 1) return -1;
      ans += (v + 2) / 3;
    }
    return ans;
  }
};
