using ll = long long;

class Solution {
public:
  long long countPairs(vector<int>& nums1, vector<int>& nums2) {
    int N = nums1.size(); vector<int> D(N);
    for (int i = 0; i < N; ++i) D[i] = nums1[i] - nums2[i];
    sort(D.begin(), D.end());

    ll ans = 0, r = N - 1;
    for (ll l = 0; l < N; ++l) {
      while (r >= 0 && D[l] + D[r] > 0) --r;
      ans += N - max(r + 1, l + 1);
    }
    return ans;
  }
};
