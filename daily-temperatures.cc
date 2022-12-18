class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    stack<pair<int, int>> P;

    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; i--) {
      while (!P.empty()) {
        auto [t, j] = P.top();
        if (t <= temperatures[i]) P.pop();
        else {
          ans[i] = j - i;
          break;
        }
      }

      P.push({temperatures[i], i});
    }

    return ans;
  }
};
