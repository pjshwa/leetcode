using ll = long long;

class Solution {
public:
  long long minSum(vector<int>& nums1, vector<int>& nums2) {
    ll sum1 = 0, sum2 = 0;
    bool chg1 = 0, chg2 = 0;

    for (int e : nums1) {
      if (e > 0) sum1 += e;
      else sum1 += 1, chg1 = 1;
    }
    for (int e : nums2) {
      if (e > 0) sum2 += e;
      else sum2 += 1, chg2 = 1;
    }

    if (sum1 == sum2) return sum1;
    if (sum1 > sum2) {
      if (chg2) return sum1;
      else return -1;
    }
    else {
      if (chg1) return sum2;
      else return -1;
    }
    return -1;
  }
};
