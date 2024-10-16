class Solution {
public:
  string longestDiverseString(int a, int b, int c) {
    string ret = "";
    priority_queue<pair<int, char>> pq;
    if (a) pq.push({a, 'a'});
    if (b) pq.push({b, 'b'});
    if (c) pq.push({c, 'c'});

    while (!pq.empty()) {
      auto [cnt1, ch1] = pq.top(); pq.pop();
      if (ret.size() >= 2 && ret.back() == ch1 && ret[ret.size() - 2] == ch1) {
        if (pq.empty()) break;
        auto [cnt2, ch2] = pq.top(); pq.pop();
        ret.push_back(ch2); --cnt2;
        if (cnt2) pq.push({cnt2, ch2});
        pq.push({cnt1, ch1});
      } else {
        ret.push_back(ch1); --cnt1;
        if (cnt1) pq.push({cnt1, ch1});
      }
    }
    return ret;
  }
};
