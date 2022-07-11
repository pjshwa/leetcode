class Solution {
  bool rem[100'000];
public:
  string minRemoveToMakeValid(string s) {
    int n = s.size();
    memset(rem, 0, sizeof(rem));

    stack<pair<int, char>> t;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') t.push({ i, '(' });
      else if (s[i] == ')') {
        if (!t.empty() && t.top().second == '(') t.pop();
        else rem[i] = true;
      }

    }

    while (!t.empty()) {
      rem[t.top().first] = true;
      t.pop();
    }

    string res = "";
    for (int i = 0; i < n; i++) {
      if (!rem[i]) res.push_back(s[i]);
    }
    return res;
  }
};
