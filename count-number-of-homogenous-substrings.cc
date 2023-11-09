using ll = long long;
const int MOD = 1e9 + 7;

int C2(int n) {
  return (ll)n * (n - 1) / 2 % MOD;
}

class Solution {
public:
  int countHomogenous(string s) {
    char l = ' '; int streak = 0, ans = 0;
    for (char c : s) {
      if (c == l) ++streak;
      else {
        l = c;
        ans = (ans + C2(streak + 1)) % MOD;
        streak = 1;
      }
    }
    ans = (ans + C2(streak + 1)) % MOD;
    return ans;
  }
};
