class Solution {
public:
  int scoreOfParentheses(string s) {
    vector<int> v{0};
    for (char c : s) {
      if (c == '(') v.push_back(0);
      else {
        int t = v.back(); v.pop_back();
        v.back() += max(2 * t, 1);
      }
    }
    return v.front();
  }
};
