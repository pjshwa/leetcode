const int MAX = 1e5;
int v[MAX + 1];

class Solution {
public:
  int minDeletions(string s) {
    map<int, int> t;
    for (char& c : s) t[c]++;

    memset(v, 0, sizeof(v));
    for (auto& p : t) v[p.second]++;

    int ans = 0;
    for (int i = MAX; i >= 1; i--) {
      if (v[i] > 1) {
        int off = v[i] - 1;
        ans += off;
        v[i - 1] += off;
      }
    }

    return ans;
  }
};
