class Solution {
public:
  int lengthOfLastWord(string s) {
    int ans = 0, i = 0, N = s.size();
    reverse(s.begin(), s.end());
    while (s[i] == ' ') ++i;
    while (i < N && s[i] != ' ') ++i, ++ans;
    return ans;
  }
};
