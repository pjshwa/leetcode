const int MAXN = 1e5, MOD = 1e9 + 7;
int L[MAXN + 1], R[MAXN + 1];

class Solution {
public:
  int specialTriplets(vector<int>& nums) {
    memset(L, 0, sizeof L); memset(R, 0, sizeof R);
    for (int e : nums) ++R[e];

    int ans = 0;
    for (int e : nums) {
      --R[e];
      int u = 2 * e;
      if (u <= MAXN) {
        ans = (ans + (long long)L[u] * R[u]) % MOD;
      }
      ++L[e];
    }
    return ans;
  }
};
