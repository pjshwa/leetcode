#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXV = 5e4;

class Solution {
public:
  vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
    vector<ll> D(MAXV + 1);
    for (int e : nums) {
      for (int d = 1; d * d <= e; ++d) {
        if (e % d) continue;
        ++D[d];
        if (d * d != e) ++D[e / d];
      }
    }

    for (int v = MAXV; v >= 1; --v) {
      D[v] = (D[v] * (D[v] - 1)) / 2;
      for (int d = 2 * v; d <= MAXV; d += v) D[v] -= D[d];
    }
    for (int v = 2; v <= MAXV; ++v) D[v] += D[v - 1];

    vector<int> ans;
    for (ll q : queries) {
      int l = 1, r = MAXV;
      while (l < r) {
        int m = (l + r) / 2;
        if (D[m] <= q) l = m + 1;
        else r = m;
      }
      ans.push_back(l);
    }
    return ans;
  }
};
