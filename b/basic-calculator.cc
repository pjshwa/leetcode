using ll = long long;

class Solution {
  string O;

  int E(int l, int r) {
    ll P = 0, C = 0; char op = 0;
    for (int i = l; i < r; i++) {
      if (O[i] == ' ') continue;

      if (O[i] == '(') {
        int open = 1, j = i + 1;
        while (open && j < r) {
          if (O[j] == '(') open++;
          if (O[j] == ')') open--;
          j++;
        }
        C = E(i + 1, j - 1);
        i = j - 1;
      }
      else if ('0' <= O[i] && O[i] <= '9') {
        C = C * 10 + O[i] - '0';
      }
      else if (O[i] == '-') {
        if (op == '+') P += C;
        else if (op == '-') P -= C;
        else P = C;
        C = 0;
        op = '-';
      }
      else if (O[i] == '+') {
        if (op == '+') P += C;
        else if (op == '-') P -= C;
        else P = C;
        C = 0;
        op = '+';
      }
    }

    if (op == '+') P += C;
    else if (op == '-') P -= C;
    else P = C;

    return P;
  }

public:
  int calculate(string s) {
    O = s;
    return E(0, O.size());
  }
};
