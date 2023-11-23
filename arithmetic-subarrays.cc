class Solution {
public:
  vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    int Q = l.size();
    vector<bool> ans(Q);
    for (int i = 0; i < Q; ++i) {
      vector<int> v(nums.begin() + l[i], nums.begin() + r[i] + 1);
      sort(v.begin(), v.end());
      int d = v[1] - v[0];
      bool ok = true;
      for (int j = 2; j < v.size(); ++j) {
        if (v[j] - v[j - 1] != d) {
          ok = false;
          break;
        }
      }
      ans[i] = ok;
    }
    return ans;
  }
};
