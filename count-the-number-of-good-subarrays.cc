using ll = long long;

class Solution {
public:
  long long countGood(vector<int>& nums, int k) {
    int n = nums.size();

    map<int, int> t; ll ans = 0, cur = 0;
    int r = 0;
    for (int l = 0; l < n; l++) {
      while (r < n && cur < k) {
        cur += t[nums[r]];
        t[nums[r]]++;
        r++;
      }

      if (cur >= k) ans += n - r + 1;

      t[nums[l]]--;
      cur -= t[nums[l]];
    }

    return ans;
  }
};
