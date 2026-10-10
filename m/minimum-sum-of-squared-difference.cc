#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
  long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
    int N = nums1.size(), L = k1 + k2, l = 0, r = 1e5;
    while (l < r) {
      int m = (l + r) / 2; ll need = 0;
      for (int i = 0; i < N; ++i) {
        int v = abs(nums1[i] - nums2[i]);
        need += max(0, v - m);
      }
      if (need <= L) r = m;
      else l = m + 1;
    }
    ll ans = 0, need = 0;
    for (int i = 0; i < N; ++i) {
      int v = abs(nums1[i] - nums2[i]);
      need += max(0, v - l);
    }
    for (int i = 0; i < N; ++i) {
      int v = abs(nums1[i] - nums2[i]);
      ll u = min(v, l);
      if (u > 0 && u == l && need < L) --u, ++need;
      ans += u * u;
    }
    assert(ans == 0 || need == L);
    return ans;
  }
};
