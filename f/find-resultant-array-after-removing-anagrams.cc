class Solution {
  bool is_anagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
  }

public:
  vector<string> removeAnagrams(vector<string>& words) {
    vector<string> ret;
    for (auto& w : words) {
      if (!ret.empty() && is_anagram(ret.back(), w)) continue;
      ret.push_back(w);
    }
    return ret;
  }
};
