class Solution {
  int d[1001];
public:
  int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    d[0] = d[1] = 0;
    for (int i = 2; i <= n; i++) d[i] = min(d[i - 1] + cost[i - 1], d[i - 2] + cost[i - 2]);
    return d[n];
  }
};
