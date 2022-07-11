class Solution {
  int d[60];
public:
  int numPairsDivisibleBy60(vector<int>& nums) {
    memset(d, 0, sizeof(d));

    int ans = 0;
    for (int num : nums) {
      ans += d[(60 - num % 60) % 60];
      d[num % 60]++;
    }

    return ans;
  }
};
