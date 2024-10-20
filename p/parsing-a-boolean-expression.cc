class Solution {
public:
  bool parseBoolExpr(string expression) {
    if (expression == "t") return true;
    if (expression == "f") return false;

    char head = expression[0];
    if (head == '!') return !parseBoolExpr(expression.substr(2, expression.size() - 3));
    else {
      vector<string> exprs; int N = expression.size();
      string expr = ""; int lev = 0;
      for (int i = 2; i < N - 1; ++i) {
        if (expression[i] == ',' && lev == 0) {
          exprs.push_back(expr), expr.clear();
          continue;
        }
        expr.push_back(expression[i]);
        if (expression[i] == '(') ++lev;
        if (expression[i] == ')') --lev;
      }
      exprs.push_back(expr);

      bool ret;
      if (head == '&') {
        ret = true;
        for (auto expr : exprs) ret &= parseBoolExpr(expr);
      } else {
        ret = false;
        for (auto expr : exprs) ret |= parseBoolExpr(expr);
      }
      return ret;
    }
  }
};
