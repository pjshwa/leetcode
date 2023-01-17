class Solution {
public:
  int minFlipsMonoIncr(string s) {
    int n = s.size();
    int zc = 0, oc = 0;
    for (char c : s) {
      if (c == '0') zc++;
      else oc++;
    }

    int ans = min(zc, oc), coc = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') zc--;
      else coc++;
      ans = min(ans, zc + coc);
    }

    return ans;
  }
};
