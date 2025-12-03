using ll = long long;
const int INF = 1e9 + 7;

class Fraction {
public:
  ll num, den;
  Fraction(ll num, ll den) : num(num), den(den) {
    reduce();
  }
  Fraction operator+(const Fraction &other) const {
    auto ret = Fraction(num * other.den + other.num * den, den * other.den);
    ret.reduce();
    return ret;
  }
  Fraction operator-(const Fraction &other) const {
    auto ret = Fraction(num * other.den - other.num * den, den * other.den);
    ret.reduce();
    return ret;
  }
  Fraction operator*(const Fraction &other) const {
    auto ret = Fraction(num * other.num, den * other.den);
    ret.reduce();
    return ret;
  }
  bool operator<(const Fraction &other) const {
    return num * other.den < other.num * den;
  }
  bool operator==(const Fraction &other) const {
    return num == other.num && den == other.den;
  }
  string to_string() const {
    return std::to_string(num) + "/" + std::to_string(den);
  }
  void reduce() {
    ll g = __gcd(num, den);
    num /= g, den /= g;
    if (den < 0) num = -num, den = -den;
  }
};

class Solution {
  ll f2i(ll dy, ll dx) {
    return dy * 50000 + dx;
  }

public:
  int countTrapezoids(vector<vector<int>>& points) {
    int N = points.size();
    map<Fraction, vector<Fraction>> intercepts_by_slope;
    map<ll, vector<Fraction>> slope_by_center;
    for (int i = 0; i < N; ++i) for (int j = i + 1; j < N; ++j) {
      ll dy = points[j][1] - points[i][1], dx = points[j][0] - points[i][0];
      Fraction slope = Fraction(dy, dx), intercept = Fraction(0, 1);
      if (dx == 0) {
        slope = Fraction(INF, 1);
        intercept = Fraction(points[i][0], 1);
      } else {
        intercept = Fraction(points[i][1] * dx - dy * points[i][0], dx);
      };
      intercepts_by_slope[slope].emplace_back(intercept);
      ll center_i = f2i(points[i][0] + points[j][0], points[i][1] + points[j][1]);
      slope_by_center[center_i].emplace_back(slope);
    }

    int ans = 0;
    for (auto& [_, v] : intercepts_by_slope) {
      unordered_map<ll, int> t;
      for (auto& intercept : v) ++t[f2i(intercept.num, intercept.den)];

      int pre = 0;
      for (auto& [_, cnt] : t) {
        ans += pre * cnt;
        pre += cnt;
      }
    }

    for (auto& [_, v] : slope_by_center) {
      unordered_map<ll, int> t;
      for (auto& slope : v) ++t[f2i(slope.num, slope.den)];

      int pre = 0;
      for (auto& [_, cnt] : t) {
        ans -= pre * cnt;
        pre += cnt;
      }
    }
    return ans;
  }
};
