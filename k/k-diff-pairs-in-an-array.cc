class Solution {
public:
  int findPairs(vector<int>& nums, int diff) {
    if (diff == 0) {
      map<int, int> u;
      for (int& num : nums) u[num]++;

      int ans = 0;
      for (auto& [k, v] : u) {
        if (v > 1) ans++;
      }
      return ans;
    }
    else {
      map<int, int> u;
      for (int& num : nums) u[num] = 1;

      int ans = 0;
      for (int& num : nums) {
        if (u[num] == 0) continue;

        if (u[num + diff]) ans++;
        if (u[num - diff]) ans++;

        u[num] = 0;
      }
      return ans;
    }
      
  }
};
