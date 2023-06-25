class Solution {
public:
  int countBeautifulPairs(vector<int>& nums) {
    int ans = 0, N = nums.size();
    for (int i = 0; i < N; i++) for (int j = i + 1; j < N; j++) {
      string si = to_string(nums[i]), sj = to_string(nums[j]);

      int df = si[0] - '0', db = sj.back() - '0';
      if (__gcd(df, db) == 1) ans++;
    }
    return ans;
  }
};
