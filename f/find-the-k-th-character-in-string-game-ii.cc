using ll = long long;

class Solution {
public:
  char kthCharacter(long long k, vector<int>& operations) {
    ll sz, i;
    for (i = 0, sz = 1; i < min(50, (int)operations.size()); ++i) {
      sz *= 2;
      if (sz >= k) break;
    }
    int ans = 0; --k;
    for (int j = i; j >= 0; --j) {
      sz /= 2;
      if (k >= sz) {
        k -= sz;
        if (operations[j]) ans = (ans + 1) % 26;
      }
    }
    return 'a' + ans;
  }
};
