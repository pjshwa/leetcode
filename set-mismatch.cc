class Solution {
public:
  vector<int> findErrorNums(vector<int>& nums) {
    int N = nums.size();
    vector<int> T(N + 1);
    for (int e : nums) T[e]++;

    vector<int> ans(2);
    for (int i = 1; i <= N; ++i) {
      if (T[i] == 2) ans[0] = i;
      if (T[i] == 0) ans[1] = i;
    }
    return ans;
  }
};
