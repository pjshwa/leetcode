class Solution {
public:
  int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int N = customers.size(), ans = 0, pre = 0;
    for (int i = 0; i < N; ++i) {
      if (grumpy[i] == 0) pre += customers[i], customers[i] = 0;
      if (i) customers[i] += customers[i - 1];
    }
    for (int i = 0; i < N; ++i) {
      if (i < minutes) ans = max(ans, customers[i]);
      else ans = max(ans, customers[i] - customers[i - minutes]);
    }
    return ans + pre;
  }
};
