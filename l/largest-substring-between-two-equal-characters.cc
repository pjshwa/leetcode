class Solution {
public:
  int maxLengthBetweenEqualCharacters(string s) {
    map<char, int> L; int N = s.size(), ans = -1;
    for (int i = 0; i < N; ++i) {
      if (L.find(s[i]) == L.end()) L[s[i]] = i;
      else ans = max(ans, i - L[s[i]] - 1);
    }
    return ans;
  }
};
