class Solution {
public:
  vector<string> commonChars(vector<string>& words) {
    map<char, int> s;
    for (auto c : words[0]) ++s[c];
    for (auto& word : words) {
      map<char, int> t;
      for (auto c : word) ++t[c];
      for (auto& [c, cnt] : s) cnt = min(cnt, t[c]);
    }

    vector<string> res;
    for (auto [c, cnt] : s) {
      while (cnt--) res.push_back(string(1, c));
    }
    return res;
  }
};
