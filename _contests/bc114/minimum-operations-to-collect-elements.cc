class Solution {
public:
  int minOperations(vector<int>& nums, int k) {
    set<int> U; int ans = 0;
    while (U.size() < k) {
      int el = nums.back(); nums.pop_back();
      ans++;
      if (el <= k) U.insert(el);
    }
    return ans;
  }
};
