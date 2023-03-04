using ll = long long;

// Sol 1 (Two Pointers)
class Solution {
public:
  long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    int n = nums.size();
    int oob_right[n + 1]; oob_right[n] = n;
    for (int i = n - 1; i >= 0; i--) {
      oob_right[i] = oob_right[i + 1];
      if (nums[i] < minK || nums[i] > maxK) oob_right[i] = i;
    }

    int r = 0, mink_cnt = 0, maxk_cnt = 0; ll ans = 0;
    for (int l = 0; l < n; l++) {
      while (r < n && (mink_cnt == 0 || maxk_cnt == 0)) {
        if (nums[r] == minK) mink_cnt++;
        if (nums[r] == maxK) maxk_cnt++;
        r++;
      }

      if (mink_cnt > 0 && maxk_cnt > 0 && oob_right[l] >= r) ans += (oob_right[l] - r + 1);

      if (nums[l] == minK) mink_cnt--;
      if (nums[l] == maxK) maxk_cnt--;
    }
    return ans;
  }
};

// Sol 2 (Binary Search + RMQ)
class Solution {
public:
  long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    int n = nums.size();
    int minr[n][20], maxr[n][20];
    for (int i = 0; i < n; i++) {
      minr[i][0] = maxr[i][0] = nums[i];
    }
    for (int j = 1; j < 20; j++) for (int i = 0; i < n; i++) {
      int ni = i + (1 << (j - 1));
      if (ni >= n) break;
      minr[i][j] = min(minr[i][j - 1], minr[ni][j - 1]);
      maxr[i][j] = max(maxr[i][j - 1], maxr[ni][j - 1]);
    }

    function<ll(int, int)> range_min = [&](int l, int r) {
      int k = 31 - __builtin_clz(r - l + 1);
      return min(minr[l][k], minr[r - (1 << k) + 1][k]);
    };
    function<ll(int, int)> range_max = [&](int l, int r) {
      int k = 31 - __builtin_clz(r - l + 1);
      return max(maxr[l][k], maxr[r - (1 << k) + 1][k]);
    };

    ll ans = 0;
    for (int i = 0; i < n; i++) {
      int lb, ub;
      {
        int l = i, r = n;
        while (l < r) {
          int m = (l + r) / 2;
          if (range_min(i, m) <= minK && range_max(i, m) >= maxK) r = m;
          else l = m + 1;
        }
        lb = l;
      }
      {
        int l = i, r = n;
        while (l < r) {
          int m = (l + r) / 2;
          if (range_min(i, m) < minK || range_max(i, m) > maxK) r = m;
          else l = m + 1;
        }
        ub = l;
      }
      ans += max(0, ub - lb);
    }
    return ans;
  }
};
