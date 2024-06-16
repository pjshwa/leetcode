class Solution {
  bool d[301];
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    set<string> u{wordDict.begin(), wordDict.end()};
    memset(d, 0, sizeof(d));

    d[0] = 1;
    int n = s.size();
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        if (d[j] && u.count(s.substr(j, i - j))) {
          d[i] = 1;
          break;
        }
      }
    }

    return d[n];
  }
};
