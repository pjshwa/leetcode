const int MOD = 26;

class Solution {
public:
  string shiftingLetters(string s, vector<int>& shifts) {
    int N = shifts.size();
    for (int i = N - 2; i >= 0; --i) {
      shifts[i] = (shifts[i] + shifts[i + 1]) % MOD;
    }

    string ans = s;
    for (int i = 0; i < N; ++i) {
      int d = (s[i] - 'a' + shifts[i]) % MOD;
      ans[i] = 'a' + d;
    }
    return ans;
  }
};
