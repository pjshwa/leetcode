#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;

class MovieRentingSystem {
  priority_queue<pii, vector<pii>, greater<pii>> unrentedByMovie[MAXN + 1];
  map<pii, int> priceMap;
  set<pii> onRent;
  priority_queue<tii, vector<tii>, greater<tii>> onRentList;

public:
  MovieRentingSystem(int n, vector<vector<int>>& entries) {
    for (auto& entry : entries) {
      int shop = entry[0], movie = entry[1], price = entry[2];
      unrentedByMovie[movie].emplace(price, shop);
      priceMap[{shop, movie}] = price;
    }
  }

  vector<int> search(int movie) {
    auto& pq = unrentedByMovie[movie];

    deque<pii> wait;
    while (!pq.empty()) {
      auto p = pq.top(); pq.pop();
      auto [price, shop] = p;
      if (onRent.count({shop, movie})) continue;
      if (!wait.empty() && wait.back() == p) continue;

      wait.push_back(p);
      if (wait.size() == 5) break;
    }

    vector<int> res;
    for (auto& p : wait) {
      auto [price, shop] = p;
      res.push_back(shop);
      pq.push(p);
    }
    return res;
  }

  void rent(int shop, int movie) {
    onRent.emplace(shop, movie);
    onRentList.emplace(priceMap[{shop, movie}], shop, movie);
  }

  void drop(int shop, int movie) {
    onRent.erase({shop, movie});
    unrentedByMovie[movie].emplace(priceMap[{shop, movie}], shop);
  }

  vector<vector<int>> report() {
    deque<tii> wait;
    while (!onRentList.empty()) {
      auto t = onRentList.top(); onRentList.pop();
      auto [price, shop, movie] = t;
      if (!onRent.count({shop, movie})) continue;
      if (!wait.empty() && wait.back() == t) continue;

      wait.push_back({price, shop, movie});
      if (wait.size() == 5) break;
    }

    vector<vector<int>> res;
    for (auto& t : wait) {
      auto [price, shop, movie] = t;
      res.push_back({shop, movie});
      onRentList.push(t);
    }
    return res;
  }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
