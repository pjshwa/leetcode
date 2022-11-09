class StockSpanner {
  stack<pair<int, int>> D;
  int tot;

public:
  StockSpanner() {
    tot = 0;
  }
  
  int next(int price) {
    while (!D.empty() && D.top().first <= price) D.pop();
    tot++;

    int ret = tot - (D.empty() ? 0 : D.top().second);
    D.push({price, tot});
    return ret;
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
