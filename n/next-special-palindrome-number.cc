using ll = long long;

class Solution {
public:
  ll specialPalindrome(ll n) {
    ll ans = 1e18;
    int P[8], C[4] = {2, 4, 6, 8}, nZ = to_string(n).size();
    vector<int> digits;
    
    // usage of 2, 4, 6, 8
    for (int s = 0; s < 16; ++s) for (int d : {1, 3, 5, 7, 9, 0}) {

      digits.clear();
      for (int i = 0; i < 4; ++i) {
        if (!(s & (1 << i))) continue;
        for (int j = 0; j < C[i] / 2; ++j) digits.push_back(C[i]);
      }
      for (int j = 0; j < d / 2; ++j) digits.push_back(d);

      int N = digits.size(), tZ = 2 * N + (d > 0);
      if (tZ < nZ || tZ > nZ + 1) continue;
      iota(P, P + N, 0);

      do {
        string p = "";
        for (int i = 0; i < N; ++i) p += to_string(digits[P[i]]);
        string p_rev = p;
        reverse(p_rev.begin(), p_rev.end());

        string res;
        if (d) res = p + to_string(d) + p_rev;
        else res = p + p_rev;
        if (res.empty()) continue;

        ll res_l = stoll(res);
        if (res_l > n && res_l < ans) ans = res_l;

      } while (next_permutation(P, P + N));
    }

    return ans;
  }
};
