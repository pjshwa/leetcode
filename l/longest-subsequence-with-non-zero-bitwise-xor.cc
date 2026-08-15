class Solution {
public:
  int longestSubsequence(vector<int>& nums) {
    int N = nums.size(), z = 0, sum = 0;
    for (int e : nums) sum ^= e, z += (e == 0);
    if (sum == 0) {
      if (z == N) return 0;
      else return N - 1;
    }
    else return N;
  }
};
