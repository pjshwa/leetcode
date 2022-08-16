class Solution {
public:
  int firstUniqChar(string s) {
    int ans = 0x3f3f3f3f;
    for (char c = 'a'; c <= 'z'; ++c) {
      int pos = s.find(c);
      if (pos != string::npos && s.find(c, pos + 1) == string::npos) {
        ans = min(ans, pos);
      }
    }
    if (ans == 0x3f3f3f3f) return -1;
    return ans;
  }
};
