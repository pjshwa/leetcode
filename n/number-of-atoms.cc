class Solution {
public:
  string countOfAtoms(string formula) {
    int i = 0, lev = 0, N = formula.size();
    map<string, int> tal[N];

    function<string()> readName = [&]() {
      string name = "";
      name += formula[i]; ++i;
      while (i < N && islower(formula[i])) {
        name += formula[i];
        ++i;
      }
      return name;
    };

    function<int()> readNum = [&]() {
      int num = 0;
      while (i < N && isdigit(formula[i])) {
        num = num * 10 + formula[i] - '0';
        ++i;
      }
      return num == 0 ? 1 : num;
    };

    while (i < N) {
      char c = formula[i];
      if (isupper(c)) {
        string name = readName();
        tal[lev][name] += readNum();
      }
      else if (c == '(') ++i, ++lev;
      else if (c == ')') {
        ++i;
        int num = readNum();
        for (auto &p : tal[lev]) tal[lev - 1][p.first] += p.second * num;
        tal[lev--].clear();
      }
      else assert(false);
    }

    string ans = "";
    for (auto &p : tal[0]) {
      ans += p.first;
      if (p.second > 1) ans += to_string(p.second);
    }
    return ans;
  }
};
