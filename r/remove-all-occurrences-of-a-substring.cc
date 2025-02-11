class Solution {
public:
  string removeOccurrences(string s, string part) {
    string ret = "";
    for (char& c : s) {
      ret.push_back(c);
      if (ret.size() >= part.size() && ret.substr(ret.size() - part.size()) == part) {
        ret.resize(ret.size() - part.size());
      }
    }
    return ret;
  }
};
