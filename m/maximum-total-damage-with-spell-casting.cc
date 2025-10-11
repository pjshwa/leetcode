using ll = long long;

class Solution {
public:
  ll maximumTotalDamage(vector<int>& power) {
    unordered_map<int, int> cnt;
    for (int p : power) ++cnt[p];

    sort(power.begin(), power.end());
    power.erase(unique(power.begin(), power.end()), power.end());

    int N = power.size();
    vector<ll> dp(N, (ll)power[0] * cnt[power[0]]);
    for (int i = 1; i < N; ++i) {
      int j = i - 1;
      while (j >= 0 && power[j] >= power[i] - 2) --j;

      ll val = (ll)power[i] * cnt[power[i]];
      if (j >= 0) val += dp[j];
      dp[i] = max(dp[i - 1], val);
    }
    return *max_element(dp.begin(), dp.end());
  }
};
