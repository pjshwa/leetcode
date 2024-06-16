class Solution {
public:
  int maxProfit(vector<int>& prices) {
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(prices[0]);

    int ans = 0, n = prices.size();
    for (int i = 1; i < n; i++) {
      ans = max(ans, prices[i] - pq.top());
      pq.push(prices[i]);
    }

    return ans;
  }
};
