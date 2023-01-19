class Solution {
public:
  int subarraysDivByK(vector<int>& nums, int k) {
    int t[k];
    memset(t, 0, sizeof(t));
    t[0] = 1;

    int run = 0, ans = 0;
    for (int num : nums) {
      run = (run + num) % k;
      if (run < 0) run += k;

      ans += t[run];
      t[run]++;
    }

    return ans;
  }
};
