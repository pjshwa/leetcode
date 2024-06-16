using ll = long long;

class Solution {
  bool is_operator(string u) {
    return u == "+" || u == "-" || u == "*" || u == "/";
  }

  ll div(ll a, ll b) {
    bool f1 = a < 0, f2 = b < 0;
    ll ret = abs(a) / abs(b);
    if (f1 ^ f2) ret = -ret;
    return ret;
  }

public:
  int evalRPN(vector<string>& tokens) {
    stack<ll> o;
    for (auto token : tokens) {
      if (is_operator(token)) {
        ll t2 = o.top(); o.pop();
        ll t1 = o.top(); o.pop();
        if (token == "+") o.push(t1 + t2);
        if (token == "-") o.push(t1 - t2);
        if (token == "*") o.push(t1 * t2);
        if (token == "/") o.push(div(t1, t2));
      }
      else o.push(stoll(token));
    }

    return o.top();
  }
};
