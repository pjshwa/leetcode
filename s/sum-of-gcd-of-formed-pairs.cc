class Solution {
public:
  long long gcdSum(vector<int>& nums) {
    deque<int> prefixGcd; int mx = 0;
    for (int e : nums) {
      mx = max(mx, e);
      prefixGcd.push_back(__gcd(e, mx));
    }
    sort(prefixGcd.begin(), prefixGcd.end());

    long long ans = 0;
    while (prefixGcd.size() > 1) {
      int f = prefixGcd.front(), b = prefixGcd.back();
      ans += __gcd(f, b);
      prefixGcd.pop_front(); prefixGcd.pop_back();
    }
    return ans;
  }
};
