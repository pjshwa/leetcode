class Solution {
  vector<int> u[26];

  vector<string> split(const string &str, string delim) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(delim, start)) != string::npos) {
      tokens.push_back(str.substr(start, end - start));
      start = end + delim.size();
    }

    tokens.push_back(str.substr(start));
    return tokens;
  }

public:
  bool wordPattern(string pattern, string s) {
    int n = pattern.size();
    for (int i = 0; i < n; i++) {
      u[pattern[i] - 'a'].push_back(i);
    }

    auto v = split(s, " ");
    if (v.size() != n) return false;

    int uc = 0;
    set<string> us;
    for (int ui = 0; ui < 26; ui++) {
      if (u[ui].size() == 0) continue;

      uc++;
      string p = v[u[ui][0]];
      us.insert(p);
      for (int i : u[ui]) {
        if (v[i] != p) return false;
      }
    }

    return uc == us.size();
  }
};
