class Solution {
public:
  string digitSum(string s, int k) {
    if (s.size() <= k) return s;

    string t;
    for (int i = 0; i < s.size(); i += k) {
      int u = 0;
      for (int j = i; j < i + k; ++j) {
        if (j == s.size()) break;
        u += s[j] - '0';
      }
      t += to_string(u);
    }
    return digitSum(t, k);
  }
};
