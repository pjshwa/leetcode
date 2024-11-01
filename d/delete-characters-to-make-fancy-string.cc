class Solution {
public:
  string makeFancyString(string s) {
    string t = "";
    for (char c : s) {
      t.push_back(c);
      int z = t.size();
      if (z >= 3 && t[z - 1] == t[z - 2] && t[z - 2] == t[z - 3]) t.pop_back();
    }
    return t;
  }
};
