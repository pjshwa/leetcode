using ll = long long;
const int MAX = 1e5;

class Solution {
  int l[MAX], r[MAX];
public:
  int largestRectangleArea(vector<int>& h) {
    int n = heights.size();
    ll max_v;
    stack<int> stk;

    for (int i = 0; i < n; i++) {
      l[i] = -1;
      r[i] = n;
    }

    for (int i = 0; i < n; i++) {
      while (!stk.empty() && h[stk.top()] >= h[i]) stk.pop();
      if (!stk.empty()) l[i] = stk.top();
      stk.push(i);
    }
    while (!stk.empty()) stk.pop();

    for (int i = n - 1; i >= 0; i--) {
      while (!stk.empty() && h[stk.top()] >= h[i]) stk.pop();
      if (!stk.empty()) r[i] = stk.top();
      stk.push(i);
    }
    while (!stk.empty()) stk.pop();

    max_v = 0;
    for (int i = 0; i < n; i++) {
      max_v = max(max_v, (ll)h[i] * (r[i] - l[i] - 1));
    }

    return max_v;
  }
};
