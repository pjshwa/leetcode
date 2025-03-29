using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;

ll lpow(ll x, ll y, ll m) {
  ll r = 1;
  x %= m;
  while (y) {
    if (y & 1) r = (r * x) % m;
    x = (x * x) % m;
    y >>= 1;
  }
  return r;
}

class Solution {
public:
  int maximumScore(vector<int>& nums, int k) {
    int N = nums.size();
    vector<int> pscore(N);
    for (int i = 0; i < N; ++i) {
      int e = nums[i];
      for (int q = 2; q * q <= e; ++q) {
        if (e % q) continue;
        ++pscore[i];
        while (e % q == 0) e /= q;
      }
      if (e > 1) ++pscore[i];
    }

    stack<pii> st;
    vector<int> pscore_r(N, N);
    for (int i = 0; i < N; ++i) {
      while (!st.empty() && st.top().first < pscore[i]) {
        pscore_r[st.top().second] = i;
        st.pop();
      }
      st.push({pscore[i], i});
    }
    while (!st.empty()) st.pop();
    vector<int> pscore_l(N, -1);
    for (int i = N - 1; i >= 0; --i) {
      while (!st.empty() && st.top().first <= pscore[i]) {
        pscore_l[st.top().second] = i;
        st.pop();
      }
      st.push({pscore[i], i});
    }

    priority_queue<pair<int, ll>> pq;
    for (int i = 0; i < N; ++i) {
      ll l = i - pscore_l[i], r = pscore_r[i] - i;
      pq.push({nums[i], l * r});
    }

    ll ans = 1;
    while (k) {
      auto [u, l] = pq.top(); pq.pop();
      ll d = min((ll)k, l);
      ans = (ans * lpow(u, d, MOD)) % MOD;
      k -= d;
    }
    return ans;
  }
};
