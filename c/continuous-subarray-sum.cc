using ll = long long;

class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    map<ll, int> t;
    ll l1 = 0, run = 0;
    for (int e : nums) {
      run = (run + e) % k;
      if (t.count(run)) return true;

      t[l1] = 1;
      l1 = run;
    }
    return false;
  }
};
