class Solution {
public:
  int minSubarray(vector<int>& nums, int p) {
    int N = nums.size(), R = 0;
    for (int e : nums) R = (R + e) % p;
    if (R == 0) return 0;
    
    map<int, int> dt; dt[0] = -1;
    int run = 0, ans = N;
    for (int i = 0; i < N; ++i) {
      run = (run + nums[i]) % p;
      int tgt = (run - R + p) % p;
      if (dt.count(tgt)) ans = min(ans, i - dt[tgt]);
      dt[run] = i;
    }
    return ans == N ? -1 : ans;
  }
};
