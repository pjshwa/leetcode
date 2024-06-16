class Solution {
public:
  string maximumOddBinaryNumber(string s) {
    int N = s.size(), oc = 0;
    for (char c : s) oc += (c == '1');

    string ans(N, '0');
    for (int i = 0; i < oc - 1; ++i) ans[i] = '1';
    ans.back() = '1';
    return ans;
  }
};
