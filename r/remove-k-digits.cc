class Solution {
public:
  string removeKdigits(string num, int k) {
    int n = num.size();
    stack<char> u;
    for (int i = 0; i < n; i++) {
      while (k && !u.empty() && u.top() > num[i]) u.pop(), k--;
      u.push(num[i]);
    }
    while (k) u.pop(), k--;

    string res = "";
    while (!u.empty()) {
      res += u.top();
      u.pop();
    }

    int ep = res.size();
    while (ep && res[ep - 1] == '0') ep--;

    if (ep == 0) return "0";
    res = res.substr(0, ep);
    reverse(res.begin(), res.end());
    return res;
  }
};
