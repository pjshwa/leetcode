class Solution {
public:
  long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
    int N = nums.size();
    for (int& e : nums) e = e % modulo == k;

    vector<int> P(N + 1);
    for (int i = 0; i < N; ++i) P[i + 1] = (P[i] + nums[i]) % modulo;

    unordered_map<int, int> tal; long long ans = 0;
    for (int e : P) {
      ans += tal[(e - k + modulo) % modulo];
      ++tal[e];
    }
    return ans;
  }
};
