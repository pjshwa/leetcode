using pii = pair<int, int>;

class Solution {
public:
  long long totalCost(vector<int>& costs, int k, int candidates) {
    priority_queue<pii, vector<pii>, greater<pii>> L, R;
    int N = costs.size();
    int used[N]; memset(used, 0, sizeof(used));

    for (int i = 0; i < candidates; i++) {
      L.push({costs[i], i});
      R.push({costs[N - i - 1], N - i - 1});
    }

    long long ans = 0;
    auto use = [&](int i) {
      if (used[i]) return;
      ans += costs[i];
      used[i] = 1;
      k--;
    };

    int i = candidates - 1, j = N - candidates;
    while (k) {
      if (L.empty()) {
        auto [rc, ri] = R.top();
        R.pop(); use(ri);
        if (j > 0) j--, R.push({costs[j], j});
      }
      else if (R.empty()) {
        auto [lc, li] = L.top();
        L.pop(); use(li);
        if (i < N - 1) i++, L.push({costs[i], i});
      }
      else {
        auto [lc, li] = L.top(); auto [rc, ri] = R.top();

        if (lc < rc || (lc == rc && li < ri)) {
          L.pop(); use(li);
          if (i < N - 1) i++, L.push({costs[i], i});
        }
        else {
          R.pop(); use(ri);
          if (j > 0) j--, R.push({costs[j], j});
        }
      }
    }

    return ans;
  }
};
