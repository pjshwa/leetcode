using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
  map<int, ll> d;
public:
  int numFactoredBinaryTrees(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
      d[arr[i]] = 1;
      for (int j = 0; j < i; j++) {
        if (arr[i] % arr[j]) continue;

        int q = arr[i] / arr[j];
        if (d.count(q)) d[arr[i]] = (d[arr[i]] + d[arr[j]] * d[q]) % MOD;
      }
    }

    int ans = 0;
    for (auto p : d) ans = (ans + p.second) % MOD;
    return ans;
  }
};
