class Solution {
public:
  bool backspaceCompare(string s, string t) {
    string sr = "", tr = "";

    for (char& c : s) {
      if (c == '#') {
        if (sr.size() > 0) sr.pop_back();
      }
      else sr += c;
    }

    for (char& c : t) {
      if (c == '#') {
        if (tr.size() > 0) tr.pop_back();
      }
      else tr += c;
    }

    return sr == tr;
  }
};
