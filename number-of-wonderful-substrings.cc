class Solution {
public:
  long long wonderfulSubstrings(string word) {
    long long d[1024]{}, ans = 0, s = 0; d[0] = 1;
    for (char c : word) {
      s ^= (1 << (c - 'a'));
      ans += d[s];
      for (int i = 0; i < 10; ++i) {
        ans += d[s ^ (1 << i)];
      }
      ++d[s];
    }
    return ans;
  }
};
