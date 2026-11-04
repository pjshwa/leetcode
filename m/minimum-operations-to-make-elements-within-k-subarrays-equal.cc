#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
  multiset<int> pqL, pqR;
  ll lsum = 0, rsum = 0;

  void pushL(int val) {
    pqL.insert(val);
    lsum += val;
  }

  int popL(int val) {
    pqL.erase(pqL.find(val));
    lsum -= val;
    return val;
  }

  void pushR(int val) {
    pqR.insert(val);
    rsum += val;
  }

  int popR(int val) {
    pqR.erase(pqR.find(val));
    rsum -= val;
    return val;
  }

  void reconcile() {
    int lz = pqL.size(), rz = pqR.size();
    if (abs(lz - rz) <= 1) return;
    if (lz > rz) pushR(popL(*pqL.rbegin()));
    else pushL(popR(*pqR.begin()));
  }

  ll getSum() {
    ll med = pqL.size() > pqR.size() ? *pqL.rbegin() : *pqR.begin();
    ll lrem = med * pqL.size() - lsum;
    ll rrem = rsum - med * pqR.size();
    return lrem + rrem;
  }

public:
  long long minOperations(vector<int>& nums, int x, int k) {
    int N = nums.size();
    pqL.clear(); pqR.clear();
    lsum = rsum = 0;
    for (int i = 0; i < x; ++i) pushL(nums[i]);
    for (int i = 0; i < x / 2; ++i) reconcile();

    vector<ll> sums(N + 1, getSum());
    for (int i = x + 1; i <= N; ++i) {
      int old = nums[i - x - 1];
      if (pqL.find(old) != pqL.end()) popL(old);
      else popR(old);
      int val = nums[i - 1];
      if (!pqR.empty() && val >= *pqR.begin()) pushR(val);
      else pushL(val);
      reconcile();
      sums[i] = getSum();
    }

    vector<vector<ll>> dp(N + 1, vector<ll>(k + 1, LLONG_MAX));
    dp[0][0] = 0;
    for (int i = 1; i <= N; ++i) {
      for (int j = 0; j <= k; ++j) dp[i][j] = dp[i - 1][j];
      if (i < x) continue;
      for (int j = 1; j <= k; ++j) {
        if (dp[i - x][j - 1] == LLONG_MAX) continue;
        dp[i][j] = min(dp[i][j], dp[i - x][j - 1] + sums[i]);
      }
    }
    return dp[N][k];
  }
};
