class Solution {
public:
  string findLexSmallestString(string s, int a, int b) {
    int N = s.size();
    b = __gcd(N, b);

    auto inc = [&](int o) {
      for (int i = o; i < N; i += 2) {
        s[i] += a;
        if (s[i] > '9') s[i] -= 10;
      }
    };

    string os = s, ans = s;
    for (int p1 = 0; p1 < 10; ++p1) {
      inc(1);
      for (int p2 = 0; p2 < 10; ++p2) {
        if (b & 1) inc(0);
        for (int it = 0; it < N; it += b) {
          rotate(s.begin(), s.begin() + b, s.end());
          if (s < ans) ans = s;
        }
      }
    }
    return ans;
  }
};
