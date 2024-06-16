using ll = long long;

const int MOD = 1e9 + 7;

class Solution {
public:
  int maxSum(vector<int>& nums1, vector<int>& nums2) {
    set<int> U;
    for (int e : nums1) U.insert(e);
    for (int e : nums2) U.insert(e);

    map<int, ll> dp; ll ans = 0;
    for (int e : U) {
      ll pre = 0;

      auto it1 = lower_bound(nums1.begin(), nums1.end(), e);
      if (it1 != nums1.begin() && it1 != nums1.end() && *it1 == e) {
        pre = max(pre, dp[*prev(it1)]);
      }
      auto it2 = lower_bound(nums2.begin(), nums2.end(), e);
      if (it2 != nums2.begin() && it2 != nums2.end() && *it2 == e) {
        pre = max(pre, dp[*prev(it2)]);
      }

      dp[e] = pre + e;
      ans = max(ans, pre + e);
    }

    return ans % MOD;
  }
};
