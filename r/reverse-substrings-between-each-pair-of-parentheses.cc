class Solution {
public:
  string reverseParentheses(string s) {
    stack<char> S; queue<char> W;
    for (char c : s) {
      if (c == ')') {
        while (S.top() != '(') {
          char t = S.top(); S.pop();
          W.push(t);
        }
        S.pop();
        while (!W.empty()) S.push(W.front()), W.pop();
      }
      else S.push(c);
    }

    string ans = "";
    while (!S.empty()) ans.push_back(S.top()), S.pop();
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
