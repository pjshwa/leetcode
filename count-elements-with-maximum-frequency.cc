class Solution {
public:
  int maxFrequencyElements(vector<int>& nums) {
    map<int, int> tal; int maxv = 0;
    for (int e : nums) ++tal[e], maxv = max(maxv, tal[e]);

    int ans = 0;
    for (auto& [_, v] : tal) if (v == maxv) ans += v;
    return ans;
  }
};
