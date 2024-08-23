using ll = long long;

class Fraction {
  ll num, den;

public:
  Fraction(ll num, ll den) : num(num), den(den) {
    reduce();
  }
  Fraction operator+(const Fraction &other) {
    auto ret = Fraction(num * other.den + other.num * den, den * other.den);
    ret.reduce();
    return ret;
  }
  Fraction operator-(const Fraction &other) {
    auto ret = Fraction(num * other.den - other.num * den, den * other.den);
    ret.reduce();
    return ret;
  }
  string to_string() {
    return std::to_string(num) + "/" + std::to_string(den);
  }
  void reduce() {
    ll g = __gcd(num, den);
    num /= g, den /= g;
    if (den < 0) num = -num, den = -den;
  }
};

class Solution {
public:
  string fractionAddition(string expression) {
    int N = expression.size(), i = 0;
    Fraction id(0, 1);

    bool f = true;
    if (expression[i] == '-') f = !f, ++i;

    function<Fraction()> next = [&]() {
      ll num = 0, den = 0;
      while (i < N && expression[i] != '/') num = num * 10 + expression[i++] - '0';
      ++i;
      while (i < N && isdigit(expression[i])) den = den * 10 + expression[i++] - '0';
      return Fraction(num, den);
    };

    Fraction ans = next();
    if (!f) ans = id - ans;

    while (i < N) {
      int sign = expression[i] == '+' ? 1 : -1; ++i;
      Fraction cur = next();
      if (sign == 1) ans = ans + cur;
      else ans = ans - cur;
    }
    return ans.to_string();
  }
};
