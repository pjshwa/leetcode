class Solution {
public:
  string decodeString(string s) {
    string res = "";
    int i = 0;
    while (i < s.size()) {
      if ('0' <= s[i] && s[i] <= '9') {
        int n = 0;
        while ('0' <= s[i] && s[i] <= '9') {
          n = n * 10 + s[i++] - '0';
        }
        i++;
        string rep = "";
        int dt = 1;
        while (dt) {
          if (s[i] == '[') dt++;
          if (s[i] == ']') dt--;
          if (dt) rep += s[i++];
        }
        i++;
        rep = decodeString(rep);
        while (n--) res += rep;
      }
      else res += s[i++];
    }
    return res;
  }
};
