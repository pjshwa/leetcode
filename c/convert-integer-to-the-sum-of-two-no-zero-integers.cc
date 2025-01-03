class Solution {
  bool is_nozero(int n) {
    string s = to_string(n);
    for (char c : s) {
      if (c == '0') return false;
    }
    return true;
  }

public:
  vector<int> getNoZeroIntegers(int n) {
    for (int a = 1; a < n; ++a) {
      int b = n - a;
      if (is_nozero(a) && is_nozero(b)) {
        return {a, b};
      }
    }
    return {};
  }
};
