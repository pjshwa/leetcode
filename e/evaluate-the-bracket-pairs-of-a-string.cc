class Solution {
public:
  string evaluate(string s, vector<vector<string>>& knowledge) {
    map<string, string> V; string key = "", ans = ""; int f = 0;
    for (auto& v : knowledge) V[v[0]] = v[1];
    for (char c : s) {
      if (c == '(') {
        f = 1;
      } else if (c == ')') {
        if (V.count(key)) ans += V[key];
        else ans += '?';
        f = 0; key = "";
      } else {
        if (f) key += c;
        else ans += c;
      }
    }
    return ans;
  }
};
