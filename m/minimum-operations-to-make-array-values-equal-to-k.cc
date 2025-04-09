class Solution {
public:
  int minOperations(vector<int>& nums, int k) {
    set<int> U;
    for (int e : nums) {
      if (e < k) return -1;
      U.insert(e);
    }

    int ans = 0;
    for (int e : U) ans += (e > k);
    return ans;
  }
};
