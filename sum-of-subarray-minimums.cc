const int MOD = 1e9 + 7;
using ll = long long;
using pii = pair<int, int>;

class Solution {
public:
  int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();

    vector<int> ml(n, -1), mr(n, -1);
    stack<pii> s;

    for (int i = 0; i < n; i++) {
      while (!s.empty() && s.top().first > arr[i]) {
        mr[s.top().second] = i;
        s.pop();
      }
      s.push({arr[i], i});
    }

    while (!s.empty()) s.pop();
    for (int i = n - 1; i >= 0; i--) {
      while (!s.empty() && s.top().first >= arr[i]) {
        ml[s.top().second] = i;
        s.pop();
      }
      s.push({arr[i], i});
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < n; i++) pq.push({arr[i], i});

    ll ans = 0;
    while (!pq.empty()) {
      auto [v, i] = pq.top(); pq.pop();
      int l = ml[i] == -1 ? -1 : ml[i];
      int r = mr[i] == -1 ? n : mr[i];

      ll addend = v;
      addend *= (i - l) * (r - i);
      addend %= MOD;
      ans = (ans + addend) % MOD;
    }
    return ans;
  }
};
