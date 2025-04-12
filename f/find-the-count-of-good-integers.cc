using ll = long long;

class Solution {
public:
  long long countGoodIntegers(int n, int k) {
    int D = (n + 1) / 2, pw = 1;
    for (int i = 0; i < D; ++i) pw *= 10;

    set<string> U;
    for (int s = pw / 10; s < pw; ++s) {
      string left = to_string(s), T;
      if (n & 1) {
        char b = left.back(); left.pop_back();
        string right = left;
        reverse(right.begin(), right.end());
        T = left + b + right;
      } else {
        string right = left;
        reverse(right.begin(), right.end());
        T = left + right;
      }
      if (stoll(T) % k) continue;
      sort(T.begin(), T.end());
      U.insert(T);
    }

    ll ans = 0, fac[11]; fac[0] = 1;
    for (int i = 1; i < 11; ++i) fac[i] = fac[i - 1] * i;

    for (auto& S : U) {
      int C[10]{};
      for (char c : S) ++C[c - '0'];

      ll cur = fac[n];
      for (int i = 0; i < 10; ++i) cur /= fac[C[i]];
      if (C[0]) {
        ll ded = fac[n - 1];
        for (int i = 0; i < 10; ++i) ded /= fac[C[i] - (i == 0)];
        cur -= ded;
      }
      ans += cur;
    }
    return ans;
  }
};
