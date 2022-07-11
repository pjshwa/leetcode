class Solution {
public:
  int findMaxLength(vector<int>& nums) {
    map<int, int> t;
    t[0] = -1;

    int pf = 0, ans = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
      nums[i] ? pf++ : pf--;
      if (t.count(pf)) ans = max(ans, i - t[pf]);
      else t[pf] = i;
    }

    return ans;
  }
};
