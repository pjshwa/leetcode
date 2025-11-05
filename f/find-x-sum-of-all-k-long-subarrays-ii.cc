#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;

class Solution {
  ordered_set<pair<int, int>> L1, L2;
  map<int, int> C; ll x, sum = 0;

  void inc(int x) {
    if (!C.count(x)) L2.insert({1, x});
    else {
      int c = C[x];
      if (L1.find({c, x}) != L1.end()) {
        L1.erase({c, x}); L1.insert({c + 1, x});
        sum += x;
      } else {
        L2.erase({c, x}); L2.insert({c + 1, x});
      }
    }
    ++C[x];
  }

  void dec(int x) {
    int c = C[x];
    if (L1.find({c, x}) != L1.end()) {
      L1.erase({c, x});
      if (c > 1) L1.insert({c - 1, x});
      sum -= x;
    } else {
      L2.erase({c, x});
      if (c > 1) L2.insert({c - 1, x});
    }
    if (--C[x] == 0) C.erase(x);
  }

  void reconcile() {
    if (L2.empty()) return;

    // Move from L2 to L1, if L2's largest is larger than L1's smallest
    auto [l2_size, l2_x] = *L2.rbegin();
    if (L1.size() < x) {
      L2.erase({l2_size, l2_x});
      L1.insert({l2_size, l2_x});
      sum += (ll)l2_size * l2_x;
      return;
    }

    auto [l1_size, l1_x] = *L1.begin();
    if (l2_size > l1_size || (l2_size == l1_size && l2_x > l1_x)) {
      L1.erase({l1_size, l1_x}); L1.insert({l2_size, l2_x});
      sum += (ll)(l2_size) * l2_x - (ll)(l1_size) * l1_x;
      L2.erase({l2_size, l2_x}); L2.insert({l1_size, l1_x});
    }
  }

public:
  vector<long long> findXSum(vector<int>& nums, int k, int x) {
    this->x = x;
    for (int i = 0; i < k; ++i) inc(nums[i]);
    while (L1.size() < x && !L2.empty()) reconcile();

    // cout << "L1 = ";
    // for (auto [c, v] : L1) cout << "(" << c << "," << v << ") ";
    // cout << "\n";
    // cout << "L2 = ";
    // for (auto [c, v] : L2) cout << "(" << c << "," << v << ") ";
    // cout << "\n";

    vector<ll> res{sum}; int N = nums.size();
    for (int i = k; i < N; ++i) {
      dec(nums[i - k]); inc(nums[i]);
      reconcile();
      res.push_back(sum);
    }

    return res;
  }
};
