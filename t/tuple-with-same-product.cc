class Solution {
public:
  int tupleSameProduct(vector<int>& nums) {
    int N = nums.size(), ans = 0;
    map<int, int> t;
    for (int i = 0; i < N; ++i) for (int j = i + 1; j < N; ++j) {
      int p = nums[i] * nums[j];
      ans += 8 * t[p]++;
    }
    return ans;
  }
};
