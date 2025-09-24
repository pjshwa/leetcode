using ll = long long;

class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) return "0";

    ll sign = 1, n = numerator, d = denominator;
    if (numerator < 0) sign *= -1, n = -n;
    if (denominator < 0) sign *= -1, d = -d;

    string res;
    if (sign == -1) res = "-";

    ll q = n / d, r = n % d;
    res += to_string(q);
    if (r == 0) return res;
    res += '.';

    unordered_map<ll, int> S;
    while (r != 0) {
      if (S.count(r)) {
        res.insert(S[r], "(");
        res.push_back(')');
        break;
      }
      S[r] = res.size();
      r *= 10;
      res.push_back('0' + (r / d));
      r %= d;
    }
    return res;
  }
};
