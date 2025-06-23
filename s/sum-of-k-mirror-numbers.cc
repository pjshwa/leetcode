using ll = long long;

class Solution {
  bool is_mirror_k(ll n, int k) {
    string s;
    while (n > 0) {
      s += to_string(n % k);
      n /= k;
    }
    string s_rev = s;
    reverse(s_rev.begin(), s_rev.end());
    return s == s_rev;
  }

public:
  long long kMirror(int k, int n) {

    vector<ll> candidates; ll sum = 0;
    auto add = [&](ll num) {
      candidates.push_back(num); sum += num;
      return candidates.size() == n;
    };

    for (int num = 1; num <= 9; ++num) {
      if (is_mirror_k(num, k) && add(num)) return sum;
    }

    for (int d = 1;; ++d) {
      int L = 1;
      for (int j = 0; j < d; ++j) L *= 10;

      for (int lhs = L / 10; lhs < L; ++lhs) {
        string lhs_s = to_string(lhs);
        string rhs_s = lhs_s;
        reverse(rhs_s.begin(), rhs_s.end());

        ll num = stoll(lhs_s + rhs_s);
        if (is_mirror_k(num, k) && add(num)) return sum;
      }

      for (int lhs = L / 10; lhs < L; ++lhs) {
        string lhs_s = to_string(lhs);
        string rhs_s = lhs_s;
        reverse(rhs_s.begin(), rhs_s.end());

        for (int mid = 0; mid < 10; ++mid) {
          ll num = stoll(lhs_s + to_string(mid) + rhs_s);
          if (is_mirror_k(num, k) && add(num)) return sum;
        }
      }
    }

    return -1;
  }
};
