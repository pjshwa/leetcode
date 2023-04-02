using ll = long long;
const int MAX = 1e5;

class Solution {
public:
  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    ll P[MAX + 1];
    memset(P, 0, sizeof(P));

    for (int p : potions) {
      ll v = (success - 1) / p + 1;
      if (v <= MAX) P[v]++;
    }

    for (int i = 1; i <= MAX; i++) P[i] += P[i - 1];

    int n = spells.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++) ans[i] = P[spells[i]];

    return ans;
  }
};
