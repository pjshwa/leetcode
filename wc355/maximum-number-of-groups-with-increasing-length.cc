using ll = long long;

class Solution {
public:
  int maxIncreasingGroups(vector<int>& usageLimits) {
    int N = usageLimits.size();
    sort(usageLimits.begin(), usageLimits.end(), greater<int>());

    int l = 1, r = N + 1;
    while (l < r) {
      int m = (l + r) / 2;

      ll def = 0;
      for (int i = 0; i < N; i++) {
        int need = m - i;
        if (need <= 0) need = 0;

        if (usageLimits[i] < need) {
          def += need - usageLimits[i];
        }
        else if (def > 0) {
          ll use = min(def, (ll)usageLimits[i] - need);
          def -= use;
        }
      }

      if (def == 0) l = m + 1;
      else r = m;
    }

    return l - 1;
  }
};
