class Solution {
public:
  int numberOfSubstrings(string s) {
    int C[3]{}, l = 0, N = s.size(), ans = 0;
    auto valid = [&C]() { return C[0] && C[1] && C[2]; };
    for (int r = 0; r < N; ++r) {
      ++C[s[r] - 'a'];
      while (l < r && valid()) --C[s[l++] - 'a'];
      ans += l;
      // cout << "l=" << l << " r=" << r << " ans=" << ans << endl;
    }
    return ans;
  }
};
  