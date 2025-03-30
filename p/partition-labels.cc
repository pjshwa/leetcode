class Solution {
public:
  vector<int> partitionLabels(string s) {
    int N = s.size(), C[26]{}, l = 0, b = 0;
    for (char c : s) ++C[c - 'a'];

    vector<int> ans;
    for (int i = 0; i < N; ++i) {
      int c = s[i] - 'a', ok = 1;
      b |= 1 << c; --C[c];
      for (int j = 0; j < 26; ++j) {
        if (!(b & (1 << j))) continue;
        ok &= C[j] == 0;
      }
      if (ok) {
        ans.push_back(i - l + 1);
        l = i + 1;
      }
    }
    return ans;
  }
};
  