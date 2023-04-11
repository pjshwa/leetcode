class Solution {
public:
  string removeStars(string s) {
    deque<char> T;
    for (char c : s) {
      if (c == '*') T.pop_back();
      else T.push_back(c);
    }
    return string(T.begin(), T.end());
  }
};
