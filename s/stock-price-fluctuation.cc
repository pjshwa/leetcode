class StockPrice {
  map<int, int> prices;
  multiset<int> prices_set;

public:
  StockPrice() {}

  void update(int timestamp, int price) {
    if (prices.count(timestamp)) {
      prices_set.erase(prices_set.find(prices[timestamp]));
    }
    prices[timestamp] = price;
    prices_set.insert(price);
  }

  int current() {
    return prices.rbegin()->second;
  }

  int maximum() {
    return *prices_set.rbegin();
  }

  int minimum() {
    return *prices_set.begin();
  }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
