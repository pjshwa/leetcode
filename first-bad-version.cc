// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

using ll = long long;

class Solution {
public:
  int firstBadVersion(int n) {
    ll left = 1, right = n;
    while (left < right) {
      ll mid = (left + right) / 2;
      if (isBadVersion(mid)) right = mid;
      else left = mid + 1;
    }

    return left;
  }
};
