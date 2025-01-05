const int MOD = 26;

class Solution {
public:
  string shiftingLetters(string s, vector<vector<int>>& shifts) {
    int N = s.size();
    vector<int> dt(N + 1, 0);
    for (auto& shift : shifts) {
      int s = shift[0], e = shift[1], dir = shift[2];
      int d = dir ? 1 : -1;
      dt[s] = (dt[s] + d + MOD) % MOD;
      dt[e + 1] = (dt[e + 1] - d + MOD) % MOD;
    }

    int run = 0; string ans = "";
    for (int i = 0; i < N; ++i) {
      run = (run + dt[i]) % MOD;
      int d = (s[i] - 'a' + run) % MOD;
      ans.push_back('a' + d);
    }
    return ans;
  }
};
