class Solution {
public:
  bool isValid(string s) {
    stack<char> t;
    for (char& c : s) {
      if (c == ')') {
        if (!t.empty() && t.top() == '(') t.pop();
        else return false;
      }
      else if (c == '}') {
        if (!t.empty() && t.top() == '{') t.pop();
        else return false;
      }
      else if (c == ']') {
        if (!t.empty() && t.top() == '[') t.pop();
        else return false;
      }
      else t.push(c);
    }
    return t.empty();
  }
};
