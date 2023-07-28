class Solution {
  bool is_digit(char c) {
    return c >= '0' && c <= '9';
  }

public:
  int maximumValue(vector<string>& strs) {
    int ans = 0;
    for (string& s : strs) {
      bool f = true;
      for (char c : s) {
        if (!is_digit(c)) {
          f = false;
          break;
        }
      }

      if (f) ans = max(ans, stoi(s));
      else ans = max(ans, (int)s.size());
    }

    return ans;
  }
};
