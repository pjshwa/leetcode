class Solution {
public:
  string addSpaces(string s, vector<int>& spaces) {
    int sp = 0;

    string res = "";
    for (int i = 0; i < s.size(); i++) {
      if (sp < spaces.size() && i == spaces[sp]) {
        res += ' ';
        sp++;
      }
      res += s[i];
    }

    return res;
  }
};
