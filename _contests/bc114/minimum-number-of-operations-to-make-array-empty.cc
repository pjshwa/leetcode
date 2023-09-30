class Solution {
public:
  int minOperations(vector<int>& nums) {
    map<int, int> tal;
    for (int el : nums) tal[el]++;

    int ans = 0;
    for (auto [k, v] : tal) {
      if (v == 1) return -1;
      ans += (v - 1) / 3 + 1;
    }
    return ans;
  }
};
