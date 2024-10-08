class Solution {
public:
  int minSwaps(string s) {
    int dt = 0, ans = 0;
    for (char c : s) {
      if (c == '[') ++dt;
      else if (dt > 0) --dt;
      else ++ans, ++dt;
    }
    return ans;
  }
};
