class Solution {
public:
  bool hasSameDigits(string s) {
    if (s.size() == 2) return s[0] == s[1];

    string ns;
    for (int i = 1; i < s.size(); ++i) {
      int c1 = s[i - 1] - '0', c2 = s[i] - '0';
      int sum = (c1 + c2) % 10;
      ns.push_back(sum + '0');
    }
    return hasSameDigits(ns);
  }
};
