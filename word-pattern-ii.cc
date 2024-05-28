class Solution {
public:
  bool wordPatternMatch(string pattern, string s) {
    map<char, string> mapping;
    int Pz = pattern.size(), Sz = s.size();
    function<bool(int, int)> dfs = [&](int pi, int si) {
      if (pi == Pz && si == Sz) {
        set<string> U;
        for (auto &p : mapping) U.insert(p.second);
        return U.size() == mapping.size();
      }
      if (pi == Pz || si == Sz) return false;

      char c = pattern[pi];
      if (mapping.count(c)) {
        string &word = mapping[c];
        int len = word.size();
        if (si + len > Sz || s.substr(si, len) != word) return false;
        return dfs(pi + 1, si + len);
      }

      for (int i = si; i < Sz; ++i) {
        string word = s.substr(si, i - si + 1);
        mapping[c] = word;
        if (dfs(pi + 1, i + 1)) return true;
        mapping.erase(c);
      }
      return false;
    };
    return dfs(0, 0);
  }
};
