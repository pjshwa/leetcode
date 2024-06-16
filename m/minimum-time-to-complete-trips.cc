using ll = long long;

class Solution {
public:
  long long minimumTime(vector<int>& time, int totalTrips) {
    ll l = 0, r = 0;
    for (ll t : time) r = max(r, t * totalTrips);
    r++;

    while (l < r) {
      ll m = (l + r) / 2, e = 0;
      for (ll t : time) e += m / t;

      if (e >= totalTrips) r = m;
      else l = m + 1;
    }

    return l;
  }
};
