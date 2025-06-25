using ll = long long;
using T = tuple<ll, int, int>;

class Solution {
  ll N, M, p1, p2, n1, n2;
  vector<ll> n1pos, n1neg, n2pos, n2neg;

  ll solve_neg(ll k) {
    ll left = 0, right = 1e11;
    while (left < right) {
      ll mid = (left + right) / 2, cnt = 0;
      for (ll e : n1neg) {
        int l = 0, r = n2pos.size();
        while (l < r) {
          int m = (l + r) / 2;
          if (-e * n2pos[m] <= mid) l = m + 1;
          else r = m;
        }
        cnt += l;
      }
      for (ll e : n2neg) {
        int l = 0, r = n1pos.size();
        while (l < r) {
          int m = (l + r) / 2;
          if (-e * n1pos[m] <= mid) l = m + 1;
          else r = m;
        }
        cnt += l;
      }
      if (cnt < k) left = mid + 1;
      else right = mid;
    }
    return -left;
  }

  ll solve_pos(ll k) {
    ll left = 0, right = 1e11;
    reverse(n2neg.begin(), n2neg.end());
    while (left < right) {
      ll mid = (left + right) / 2, cnt = 0;
      for (ll e : n1pos) {
        int l = 0, r = n2pos.size();
        while (l < r) {
          int m = (l + r) / 2;
          if (e * n2pos[m] <= mid) l = m + 1;
          else r = m;
        }
        cnt += l;
      }
      for (ll e : n1neg) {
        int l = 0, r = n2neg.size();
        while (l < r) {
          int m = (l + r) / 2;
          if (e * n2neg[m] <= mid) l = m + 1;
          else r = m;
        }
        cnt += l;
      }
      if (cnt < k) left = mid + 1;
      else right = mid;
    }
    return left;
  }

public:
  long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
    N = nums1.size(), M = nums2.size();
    for (int i = 0; i < N; ++i) {
      if (nums1[i] < 0) n1neg.push_back(nums1[i]);
      if (nums1[i] > 0) n1pos.push_back(nums1[i]);
    }
    for (int i = 0; i < M; ++i) {
      if (nums2[i] < 0) n2neg.push_back(nums2[i]);
      if (nums2[i] > 0) n2pos.push_back(nums2[i]);
    }
    p1 = n1pos.size(), p2 = n2pos.size(), n1 = n1neg.size(), n2 = n2neg.size();
    ll z = N * M - (p1 * p2 + n1 * n2) - (n1 * p2 + n2 * p1);
    if (k <= n1 * p2 + n2 * p1) return solve_neg(n1 * p2 + n2 * p1 - k + 1);
    else if (k - (z + n1 * p2 + n2 * p1) >= 1) return solve_pos(k - (z + n1 * p2 + n2 * p1));
    else return 0;
  }
};
