class Solution {
public:
  vector<int> diffWaysToCompute(string expression) {
    int isAllDigit = 1;
    for (char c : expression) isAllDigit &= isdigit(c);
    if (isAllDigit) return {stoi(expression)};

    vector<int> ret;
    for (int i = 0; i < expression.size(); ++i) {
      char c = expression[i];
      if (isdigit(c)) continue;

      string leftExp = expression.substr(0, i);
      string rightExp = expression.substr(i + 1);
      vector<int> leftV = diffWaysToCompute(leftExp);
      vector<int> rightV = diffWaysToCompute(rightExp);
      for (int eleL : leftV) for (int eleR : rightV) {
        if (c == '+') ret.push_back(eleL + eleR);
        if (c == '-') ret.push_back(eleL - eleR);
        if (c == '*') ret.push_back(eleL * eleR);
      }
    }
    return ret;
  }
};
