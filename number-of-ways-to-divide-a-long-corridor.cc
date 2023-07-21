const int MOD = 1e9 + 7;

class Solution {
public:
  int numberOfWays(string corridor) {
    int sc = 0;
    for (auto c : corridor) sc += c == 'S';
    if (sc == 0 || sc % 2 == 1) return 0;

    vector<int> pss;
    int x = 1, f = 1, pc = 0;
    for (auto c : corridor) {
      if (c == 'S') {
        if (x && f == 0) pss.push_back(pc);
        x ^= 1; pc = 0; f = 0;
      }
      else if (x) pc++;
    }

    long long ans = 1;
    for (auto e : pss) ans = ans * (e + 1) % MOD;
    return ans;
  }
};
