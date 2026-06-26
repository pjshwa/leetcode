#include <bits/stdc++.h>
using namespace std;

class Fenwick {
public:
  explicit Fenwick(int n) : bit_(n + 1, 0) {}

  void add(int idx, int delta) {
    for (int n = (int)bit_.size(); idx < n; idx += idx & -idx) {
      bit_[idx] += delta;
    }
  }

  int sum(int idx) const {
    int ret = 0;
    for (; idx > 0; idx -= idx & -idx) {
      ret += bit_[idx];
    }
    return ret;
  }

private:
  vector<int> bit_;
};

class Solution {
public:
  long long countMajoritySubarrays(vector<int>& nums, int target) {
    int n = (int)nums.size();
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
    }

    vector<int> vals = pref;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    Fenwick fw((int)vals.size());
    long long ans = 0;
    for (int x : pref) {
      int rank = (int)(lower_bound(vals.begin(), vals.end(), x) - vals.begin()) + 1;
      ans += fw.sum(rank - 1);
      fw.add(rank, 1);
    }
    return ans;
  }
};
