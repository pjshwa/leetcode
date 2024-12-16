class Solution {
public:
  vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    int N = nums.size();
    vector<int> ans = nums;

    while (k--) {
      int pi = 0, val = ans[0];
      for (int i = N - 1; i >= 0; --i) {
        if (val >= ans[i]) val = ans[i], pi = i;
      }
      ans[pi] *= multiplier;
    }
    return ans;
  }
};
