using ll = long long;

class Solution {
public:
  long long maximumSum(vector<int>& nums) {
    vector<int> squares;
    for (int i = 1; i <= 100; ++i) squares.push_back(i * i);

    int N = nums.size(); ll ans = 0;
    for (int s = 1; s <= N; ++s) {
      ll cur = 0;
      for (int q : squares) {
        int i = s * q - 1;
        if (i >= N) break;
        cur += nums[i];
      }
      ans = max(ans, cur);
    }
    return ans;
  }
};
