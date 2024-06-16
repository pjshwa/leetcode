class Solution {
  bool f(char a, char b) {
    if ('A' <= a && a <= 'Z') return a == b - 'a' + 'A';
    if ('a' <= a && a <= 'z') return a == b - 'A' + 'a';
    return false;
  }

public:
  string makeGood(string s) {
    vector<char> ans;
    for (char c : s) {
      if (!ans.empty() && f(ans.back(), c)) ans.pop_back();
      else ans.push_back(c);
    }
    return string(ans.begin(), ans.end());
  }
};
