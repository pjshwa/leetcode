using ll = long long;

class Solution {
public:
  long long repairCars(vector<int>& ranks, int cars) {
    ll l = 1, r = 1e14;
    while (l < r) {
      ll mins = (l + r) / 2, cnt = 0;
      for (auto rank : ranks) {
        ll q = sqrt(mins / rank);
        cnt += q;
      }
      if (cnt >= cars) r = mins;
      else l = mins + 1;
    }
    return l;
  }
};
