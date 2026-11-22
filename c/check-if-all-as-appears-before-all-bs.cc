class Solution {
public:
  bool checkString(string s) {
    int f = 0;
    for (char c : s) {
      if (c == 'a') {
        if (f) return false;
      }
      else f = 1;
    }
    return true;
  }
};
