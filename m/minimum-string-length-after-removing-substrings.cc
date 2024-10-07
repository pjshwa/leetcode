class Solution {
public:
  int minLength(string s) {
    string t;
    for (char c : s) {
      t.push_back(c);
      if (t.size() < 2) continue;

      char c2 = t.back(); t.pop_back();
      char c1 = t.back();
      if (c1 == 'A' && c2 == 'B') t.pop_back();
      else if (c1 == 'C' && c2 == 'D') t.pop_back();
      else t.push_back(c2);
    }
    return t.size();
  }
};
