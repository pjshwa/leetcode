#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

class Solution {
public:
  int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
    int n = plants.size(), refills = 0;
    int ca = capacityA, cb = capacityB;
    for (int i = 0; i < n / 2; i++) {
      if (ca < plants[i]) ca = capacityA, refills++;
      if (cb < plants[n - i - 1]) cb = capacityB, refills++;
      ca -= plants[i], cb -= plants[n - i - 1];
    }

    if (n & 1) {
      if (ca >= cb) {
        if (ca < plants[n / 2]) refills++;
      }
      else {
        if (cb < plants[n / 2]) refills++;
      }
    }

    return refills;
  }
};

int main() {
  // cout << (new Solution())->closestCost({1, 7}, {3, 4}, 10) << endl;
  // cout << (new Solution())->closestCost({3, 10}, {2, 5}, 9) << endl;
  // cout << (new Solution())->closestCost({2, 3}, {4, 5, 100}, 18) << endl;
  // cout << (new Solution())->closestCost({10}, {1}, 1) << endl;
}
