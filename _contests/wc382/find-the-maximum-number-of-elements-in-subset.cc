using ll = long long;

const int LIM = 1e9;

class Solution {
public:
  int maximumLength(vector<int>& nums) {
    unordered_map<ll, int> T;
    for (int x : nums) ++T[x];

    int oc = T[1];
    if (oc % 2 == 0) --oc;
    int ans = max(1, oc);

    for (int b = 2; b * b <= LIM; ++b) {
      ll p = b; int cnt = 0;
      while (T.count(p) && T[p] >= 2) {
        cnt += 2;
        p = p * p;
      }
      if (cnt == 0) continue;

      if (T.count(p) && T[p] == 1) ans = max(ans, cnt + 1);
      else ans = max(ans, cnt - 1);
    }

    return ans;
  }
};
